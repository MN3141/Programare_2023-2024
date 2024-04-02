import json
cities=["Caerlon","Lymhurst","Thetford"]
items=["Wood","Hide","Fabric"]
prices=["12","22","11"]
item_file=[]
for i in range(3):
    item_file.append({"Name":cities[i],"Item":items[i],"Price":prices[i]})
print(item_file)   