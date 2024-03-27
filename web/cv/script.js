console.log("TEST");
let temp=document.getElementById("geo-loc");
let counter=0;
function toggleDarkMode()
{
    console.log("Test toggle");
    let toggle= document.body;
    toggle.classList.toggle("body-dark-mode");
    console.log("Iesire toggle");
}
function growFontSize()
{
  console.log("Intrare functie growFontSize()");
  document.body.style.fontSize="150%";
}
function lowFontSize()
{
  document.body.style.fontSize="30%";
}
function detectLocation()
{
    console.log("Test Geolocation API");
    if (navigator.geolocation) {
        
        navigator.geolocation.watchPosition(showPosition);
      } else { 
        temp.innerHTML = "Geolocation is not supported by this browser.";
      }
}
function showPosition(position) {
    temp.innerHTML="Latitude: " + position.coords.latitude + 
    "<br>Longitude: " + position.coords.longitude;
}
