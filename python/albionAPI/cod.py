import requests
import json
#There’s a 4096 character limit for the url length.
def api_request():
    item_string="T2_WOOD,T3_WOOD" #refining
    web_data=requests.get("https://west.albion-online-data.com/api/v2/stats/View/"+item_string+"?locations=Caerleon,Bridgewatch")
    print(web_data.status_code)
    data=web_data.json()
    data_bytes=json.dumps(data,indent=1).encode("utf-8")
    with open("chartFile.txt","wb") as fout:
        fout.write(data_bytes)
    fout.close()
api_request()
