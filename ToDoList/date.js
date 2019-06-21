const date = document.querySelector(".date_JS");

var today = new Date();
var dd = today.getDate();
var mm = today.getMonth() + 1;
var yy = today.getFullYear();

if (dd < 10) dd = "0" + dd;
if (mm < 10) mm = "0" + mm;

date.innerHTML = yy + "." + mm + "." + dd;
