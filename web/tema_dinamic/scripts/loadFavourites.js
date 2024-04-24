console.log("Loading favourite items...");
let itemNames = Object.keys(localStorage);
let itemCities = Object.values(localStorage);
{
        let htmlElement = "<ul>";
        let dataSize = localStorage.length;
        let buttonBegin = "<button onclick=removeItem(this)>";
        let buttonEnd = "</button>";
        let buttonMessage = "Remove item";
        for (let i = 0; i < dataSize; i++) {
                htmlElement += "<li id=remove>" + itemNames[i] + ":" + itemCities[i] + "<br>"
                        + buttonBegin + buttonMessage + buttonEnd + "</li>";
        }
        htmlElement += "</ul>";
        console.log(htmlElement)
        document.querySelector("#list").innerHTML = htmlElement;
}