function removeItem(button){
    console.log("Removing selected item...");
    let removedItem=button.parentNode.innerText.replace("Remove item","");
    let buffer1=removedItem.split(":");
    localStorage.removeItem(buffer1[0]);
    document.querySelector("#remove").remove();
}