var list = new Array();

function load()
{
	var cook = getCookie("cook").split(',');
	for (var i = 0; i < cook.length; i++)
	{
		add(cook[i]);
		console.log(cook[i]);
	}

}

function setCookie(cname, cvalue, exdays)
{

   var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires="+d.toUTCString();
    document.cookie = cname + "=" + cvalue + "; " + expires;
}

function getCookie(cname)
{
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ')
        	c = c.substring(1);
        if (c.indexOf(name) == 0)
        	return c.substring(name.length, c.length);
    }
    return "";
}

function delCookie(cname)
{
	var index = -1;
	for(i = 0; i<list.length; i++)
	{
		if(list[i] == cname)
		{	
			index = i;
			break;
		}
	}
	if(index > -1)
	{
		delete list[index];
		setCookie('cook', list, 1);
	}
}

function add(todo)
{
	var newdiv = document.createElement("div");
	newdiv.innerHTML = todo;
	newdiv.style.cursor = "pointer";
	newdiv.onclick = function()
	{
		if (confirm("Do you really want to delete that ? Seems important to me ? Did you even try'ed to do it ?"))
		{
			newdiv.parentNode.removeChild(newdiv);
			delCookie(todo);
		}
	}
	verif = document.getElementById("ft_list");
	document.getElementById("ft_list").insertBefore(newdiv, verif.firstChild);
	list.push(todo);
	setCookie('cook', list, 1);


}

function test()
{
	var todo = prompt("WHAT DO YOU NEED TO DO THAT YOU CAN'T REMEMBER ?");
	if (todo != null)
		add(todo);
}
