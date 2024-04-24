console.log("Loading add button script...");
function addItem(button) {
    console.log("Adding item...");
    let selectedItem = button.parentNode.innerText.replace("Add to favourites", "");
    console.log(selectedItem);
    let buffer0 = selectedItem.split(":");
    localStorage.setItem(buffer0[0], buffer0[1]);
}