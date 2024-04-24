console.log("Fetching data...");
const PRICE_URL_BEGIN = "https://west.albion-online-data.com/api/v2/stats/Prices/";
const PRICE_URL_END = ".json?locations=Caerleon,Martlock,Bridgewatch,Lymhurst,Fort%20Sterling,Thetford&qualities=1";
const IMG_URL_BEGIN = "https://render.albiononline.com/v1/item/";
const IMG_URL_END = ".png";
let itemID = ["T2_WOOD", "T3_WOOD", "T4_WOOD", "T5_WOOD", "T6_WOOD", "T5_CAPEITEM_KEEPER@1"];
//pt a citi dintr-un JSON,tot de mecanismul de fetch ne folosim!
let itemNames = ["Birch Logs", "Chestnut Logs", "Pine Logs", "Cedar Logs", "Bloodoak Logs", "Expert's Keeper Cape"];
let arraySize = itemID.length;
fetch("/items_info_list.json")    .then(resp => {
    if (resp.ok) {
        console.log("Fetching succesful");
        return resp.json();
    }
    else
        console.log("Fetching failed");
})
fetch(PRICE_URL_BEGIN + itemNames + PRICE_URL_END)
    .then(resp => {
        if (resp.ok) {
            console.log("Fetching succesful");
            return resp.json();
        }
        else
            console.log("Fetching failed");
    })
    .then(data => {
        let htmlElement = "<ul>";
        let dataSize = data.length;
        let buttonBegin = "<button onclick=addItem(this)>";
        let buttonEnd = "</button>";
        let buttonMessage = "Add to favourites";
        for (let i = 0; i < dataSize; i++) {
            htmlElement += "<li>" + data[i]["item_id"] + ":" + data[i]["city"] + "<br>"
                + buttonBegin + buttonMessage + buttonEnd + "</li>";
        }
        htmlElement = htmlElement + "</ul>";
        document.querySelector("#item-article").innerHTML = htmlElement;
    })