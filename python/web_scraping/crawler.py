import requests
import pandas
import sys
from bs4 import BeautifulSoup
HYPERLINK="http://csac.ulbsibiu.ro/"
CLASS_NAME="menu"
ENCODING="utf-8"
def fetch_data(link):
    response=requests.get(link)
    while not response.ok:
        print("Fetch failed!")
        response=requests.get(link)
    response.encoding=ENCODING#pt afisarea caracterelor romanesti
    return response.text
def parse_data(html_code):
    scrapped_data=[]
    html_parser=BeautifulSoup(html_code,"html.parser")
    menu_data=html_parser.find(class_=CLASS_NAME)
    if menu_data:
        for tag in menu_data.find_all("a"):
            scrapped_data.append(tag.get_text())
    else:
        print("Menu not found!")
    return scrapped_data
def write_data(file_name,data):
    file=pandas.DataFrame(data)
    file.to_excel(file_name,sheet_name="Sheet 0",index=False,header=False)
web_page=fetch_data(HYPERLINK)
data=parse_data(web_page)
write_data(sys.argv[1],data)
#py crawler.py test.xlsx
#       0       1