from bs4 import BeautifulSoup
import requests
ENCODING="utf-8"
web_request=requests.get("http://csac.ulbsibiu.ro/")
while web_request.ok == False:
    print("Fetch failed!")
    web_request=requests.get("http://csac.ulbsibiu.ro/")
web_request.encoding=ENCODING#if we ignore this line of code,the parsing might fail due to potential different encoding
html_parser=BeautifulSoup(web_request.text,"html.parser")
fout=open("test.html",'w',encoding=ENCODING)
fout.write(html_parser.prettify())
fout.close()
menu_data=html_parser.find(class_="menu")
menu_data_text=[]
if menu_data:
   print("Element found")
   for tag in menu_data.find_all("a"):
     menu_data_text.append(tag.get_text())
else:
    print("Error! Element not found.")
print(menu_data_text)