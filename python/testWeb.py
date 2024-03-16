#Pentru a instala pachetul "request" scrie in consola:
#python -m pip install requests
#site de unde se pot teste functionalitatile:
#https://httpbin.org/#/
import requests
x = requests.get('https://ro.wikipedia.org/wiki/IPRS')
y=x.text#primeste corpul fisierului HTML
y=bytes(y,"utf-8")
with open("webFiles/iprs.html","wb") as fout:
    fout.write(y)
fout.close()
x=requests.get("https://httpbin.org/status/404")
print(x.url)
print(x.status_code)
x=requests.get("https://louis-dr.github.io/ternaryalu/NOTs_diode.png")
with open("webFiles/img.png","wb") as fout:
    fout.write(x.content)
fout.close()
