var form = document.querySelector(".inputform");
var task = document.querySelector("input");
var list = document.querySelector(".todolist");

const toDos = [];

function delete_List(event) {
  var n = event.target.id;
  var btn = document.getElementById(n);
  btn.remove();
}
function make_List(text) {
  var li = document.createElement("li");
  var ch = document.createElement("label");
  ch.innerText = "ⓧ";
  ch.addEventListener("click", delete_List);
  var span = document.createElement("span");
  span.innerText = text;
  li.appendChild(ch);
  li.appendChild(span);
  list.appendChild(li);
  const toDoObj = {
    text: text,
    id: toDos.length + 1
  };
  toDoObj.text = text;
  toDos.push(toDoObj);
  li.id = toDoObj.id;
  ch.id = toDoObj.id;
}

form.addEventListener("submit", function() {
  event.preventDefault();
  var str = task.value;
  make_List(str);
  task.value = "";
});
