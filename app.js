/*jshint esversion: 10 */

let btn = [...document.querySelectorAll("#btn")];
const txt = document.querySelector(".txt");
const lightMode = document.querySelector(".light-mode");
const body = document.querySelector(".body")

lightMode.addEventListener("click" , () =>{
  lightMode.classList.toggle("dark-mode");
  body.classList.toggle("body-light");
});




btn.map((button) => {
  button.addEventListener("click", (e) => {
    let numbers = e.target.innerHTML.toLocaleString();
    switch (numbers) {
      case "=":
        try {
          txt.innerHTML = eval(txt.innerHTML);
        } catch (error) {
          alert("Error");
        }
        break;
      case "RESET":
        txt.innerHTML = "";
        break;
      case "DEL":
        txt.innerHTML = txt.innerHTML.slice(0, -1);
        break;
      default:
        txt.innerHTML += numbers;
        break;
    }
  });
});
