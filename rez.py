# -*- coding: utf8 -*-

import telebot
import time
from telebot import types
from bs4 import BeautifulSoup
from selenium import webdriver

client = telebot.TeleBot('1740824140:AAHTYFUe4LBdJ3H9KwtEtV7RemmO-DXPcQ4')


@client.message_handler(commands=['start'])
def start(message):
    msg = client.send_message(message.chat.id, 'Привет')
    client.register_next_step_handler(msg, get_text_messages)


@client.message_handler(commands=['discord'])
def url(message):
    markup = types.InlineKeyboardMarkup()
    btn_my_site = types.InlineKeyboardButton(text='Я КНОПКА', url='https://discord.gg/dfmGpAjjty')
    markup.add(btn_my_site)
    client.send_message(message.chat.id, "Нажми на кнопку и перейди на наш Discord сервер.", reply_markup=markup)


@client.message_handler(content_types=['text'])
def get_text_messages(message):
    if message.text == "Привет":
        markup = types.ReplyKeyboardMarkup(row_width=2)
        itembtn1 = types.KeyboardButton('По Гос Номеру')
        itembtn2 = types.KeyboardButton('По Фото')

        markup.add(itembtn1, itembtn2)
        msg = client.send_message(message.chat.id, 'Выберите, как искать автомобиль', reply_markup=markup)
        client.register_next_step_handler(msg, user_answer)
    elif message.text == "/help":
        client.send_message(message.from_user.id, "Напиши Привет")
    elif message.text == "привет":
        client.send_message(message.from_user.id, "Напиши с большой буквы!!!")
    else:
        client.send_message(message.from_user.id, "Я тебя не понимаю. Напиши /help.")


def user_answer(message):
    if message.text == "По Гос Номеру":
        msg = client.send_message(message.chat.id, "введите номер")

        client.register_next_step_handler(msg, user_reg)


def user_reg(message):
    f = open('num.txt', 'w')
    f.write(message.text)
    f.close()
    client.send_message(message.from_user.id, f"Введённый номер: {message.text}"+"\nПодождите несколько секунд")

    p = open('num.txt', 'r')
    x = p.readline()
    p.close()

    y = (r'https://auto.ru/history/' + x + '/')

    chromedriver = 'D:\sas\chromedriver.exe'
    options = webdriver.ChromeOptions()
    options.add_argument('headless')

    browser = webdriver.Chrome(executable_path=chromedriver, options=options)
    browser.get(y)

    time.sleep(15)
    browser.close()

    browser = webdriver.Chrome(executable_path=chromedriver, options=options)
    browser.get(y)
    time.sleep(2)
    requiredHtml = browser.page_source

    soup = BeautifulSoup(requiredHtml, 'html.parser')
    name = soup.find('div', class_='VinReportPreviewExp__mmm').text
    msg = client.send_message(message.chat.id, f"Марка: {name}")
    client.register_next_step_handler(msg, user_answer)


client.polling(none_stop=True, interval=0)
