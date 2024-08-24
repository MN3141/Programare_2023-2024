#Pentru a instala pachetul "request" scrie in consola:
#python -m pip install requests
#site de unde se pot teste functionalitatile:
#https://httpbin.org/#/
import requests
import json
def test0(): #preluare fisier HTML
    x = requests.get('https://ro.wikipedia.org/wiki/IPRS')
    y=x.text#primeste corpul fisierului HTML
    y=bytes(y,"utf-8")
    with open("webFiles/iprs.html","wb") as fout:
        fout.write(y)
    fout.close()
    print(x.encoding) #standardul de codificare text(ASCII,UTF...)
def test1(): #testare cod HTTP si preluare imagine
    x=requests.get("https://httpbin.org/status/404")
    print(x.url)
    print(x.status_code)
    x=requests.get("https://louis-dr.github.io/ternaryalu/NOTs_diode.png")
    #OBS:folosind metoda get() se pot prelua si link-uri de descarcare a fisierelor
    #   (ex:preluare fisier .rar de la sectiunea "Downloads")
    with open("webFiles/img.png","wb") as fout:
        fout.write(x.content)
    fout.close()
def test2(): #testare accesare continut
    webData=requests.get("https://albionix.app/#/farmingProfit")
    with open("webFiles/webContent.txt","wb") as fout:
        fout.write(webData.content)
    fout.close()
    with open("webFiles/webText.txt","wb") as fout:
        temp=bytes(webData.text,webData.encoding)
        fout.write(temp)
    fout.close()
    #OBS:content si text memoreaza acelasi fisier HTML
    #    doar ca in tipuri diferite de date(bytes,respectiv string)
    print(webData.json())
def test3(): #testare argumente URL
    url_args={"name": "Vasilie","department": "Cybernetics"}
    webData=requests.get("https://httpbin.org/get",params=url_args)
    print(webData.url)
    print(webData.text)
    url_args={"username":"iprs","password":"balgradNexus"}
    webData=requests.post("https://httpbin.org/post",data=url_args)
    print(webData.text)
def test4(): #testare preluare date sub forma json
    web_data=requests.get("https://api.github.com/events")
    #.json() returneaza un dictionar,nu string
    temp=json.dumps(web_data.json(),indent=2)#formatare ca string si indentare date
    file_buffer=json.dumps(web_data.json(),indent=1).encode("utf-8")#formatare ca octeti
    with open("webFiles/data.json","wb") as fout:
       fout.write(file_buffer)
    fout.close()
def test5():#test API
    url="https://rickandmortyapi.com/api/"
    end_point="character"
    web_data=requests.get(url+end_point)
    data=web_data.json()
    data_string=json.dumps(data,indent=2)#formatare informatie pt o mai buna vizualizare
    print(data_string)
    data_string=data_string.encode("utf-8")
    with open("webFiles/data2.json","wb") as fout:
        fout.write(data_string)
    fout.close()
    print(len(data))#numarare cate chei se afla in dictionar
    print(data.keys())#aflare chei din dictionar
    for index in data["results"]:
        print(index["name"])
test5()