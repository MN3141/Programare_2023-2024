import requests
import json
#There’s a 4096 character limit for the url length.
def api_request():
    item_string="T2_WOOD,T3_WOOD,T4_WOOD"
    url="https://west.albion-online-data.com/api/v2/stats/Prices/"+item_string+".json?locations=Caerleon,Martlock,Bridgewatch,Lymhurst,Fort Sterling,Thetford&qualities=1"
    web_data=requests.get(url)
    print(url)
    print(web_data.status_code)
    data=web_data.json()
    data_bytes=json.dumps(data,indent=1)
    with open("chartFile.txt","a") as fout:
        fout.write(data_bytes)
    fout.close()
api_request()
