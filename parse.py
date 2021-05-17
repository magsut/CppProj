from bs4 import BeautifulSoup
from selenium import webdriver

f = open('num.txt', 'r')
x = f.readline()
f.close()

y = (r'https://auto.ru/history/' + x + '/')

chromedriver = 'D:\sas\chromedriver.exe'
options = webdriver.ChromeOptions()
options.add_argument('headless')
browser = webdriver.Chrome(executable_path=chromedriver, options=options)

browser.get(y)
requiredHtml = browser.page_source

soup = BeautifulSoup(requiredHtml, 'html.parser')
name = soup.find('div', class_='VinReportPreviewExp__mmm').text
print(name)
