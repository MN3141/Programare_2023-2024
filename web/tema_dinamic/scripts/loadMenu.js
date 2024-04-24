console.log("Loading  navigation menu...");
const NAV_MENU_ID = "nav-menu";
const htmlDirectoryPath = "pages/";
let pageLinks = ["index.html", "favourites.html", "info.html"];
let pageLinkNames = ["Main", "Favourites", "Info"];
let size = pageLinks.length;
let htmlElement = "<u id=" + NAV_MENU_ID + ">";
if (window.location.pathname.indexOf("index.html") > 0) {
    for (let i = 1; i < size; i++)
        pageLinks[i] = htmlDirectoryPath + pageLinks[i];
}
else {
    pageLinks[0] = "../" + pageLinks[0];
}
for (let i = 0; i < size; i++) {
    pageLinks[i] = "\"" + pageLinks[i] + "\"";//pentru includerea " "
    htmlElement = htmlElement + "<li>" + "<a href=" +
        pageLinks[i] + ">" + pageLinkNames[i] +
        "</a>" + "</li>";
}
htmlElement = htmlElement + "</u>";
document.getElementById("menu").innerHTML = htmlElement;
