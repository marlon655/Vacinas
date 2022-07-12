window.onload = function (){
let icon = document.querySelector(".icon h2");
let menu = document.querySelector(".menu");
let header = document.querySelector(".header");
let conteudo = document.querySelector(".content");

//--Abre e Fecha menu--
var open = true;
icon.addEventListener("click", function(){
	if(open){
		open = false;
		icon.textContent = '>>';
		console.log("fechou");
		header.style.width = "100%";
		menu.style.display = "none";
		conteudo.style.width="100%";
	}else{
		open = true;
		icon.textContent = '<<';
		console.log("abriu");
		menu.style.display = "block";
		header.style.width = (conteudo.offsetWidth - menu.offsetWidth) + "px";
		conteudo.style.width= (conteudo.offsetWidth - menu.offsetWidth) + "px";
	}
});
window.addEventListener('resize',()=>{
	if (open) {
		menu.style.display = "block";
		header.style.width = (document.body.clientWidth - menu.offsetWidth) + "px";
		conteudo.style.width= (document.body.clientWidth - menu.offsetWidth) + "px";
	}
});
};

