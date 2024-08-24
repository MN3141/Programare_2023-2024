import json
ITEM_FILE="C:\\Arhiva_ULBS\\Proiecte\\Anul_II\\albion_royal_market\\InputFiles\\python\\output\\json\\api_items_price.json"
fin=open(ITEM_FILE,"r")
items_buffer=json.load(fin)
fin.close()
price_sell=items_buffer["price_sell"]
price_buy=items_buffer["price_buy"]
test=items_buffer["T5_WOOD"]["recipe"]
cost=0
cost2=0
for i in range (len(test["buy"])):
    cost=cost+(int)(test["buy"][i][2])*(int)(test["buy"][i][3])+(int)(test["buy"][i][4])
print(cost)
for i in range (len(test["craft"])):
    cost2=cost2+(int)(test["craft"][i][2])*(int)(test["craft"][i][4])
print(cost2)
