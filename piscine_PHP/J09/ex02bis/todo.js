var list = new Array();


$(document).ready(function(){
	var spl = $.cookie('cook');
	var s = spl.split(',');
	var i = 0;
	while(i < s.length)
	{
		var newDiv ="<div style='cursor:pointer' class='sup' rel = '"+s[i]+"'>"+s[i]+"</div>";
		$('#ft_list').append(newDiv);
		list.push(s[i]);
		i++;
	}
});
$('body').on('click','.sup', function(){
	if (confirm("Do you really want to delete that ? Seems important to me ? Did you even try'ed to do it ?"))
	{
		$(this).remove();
		var index = -1;
		for(i = 0; i<list.length; i++)
		{
			if(list[i] == $(this).attr('rel'))
			{	
				index = i;
				break;
			}	
		}
		if(index > -1)
		{
			var a = $(this).attr('rel');
			var i = -1;
			if( (i = jQuery.inArray(a, list)) >= 0)
				list.splice(jQuery.inArray(a, list), 1);
			$.cookie('cook', list, 1);
		}
	}
})

$('#subm').on('click', function(){
	var todo = prompt("WHAT DO YOU NEED TO DO THAT YOU CAN'T REMEMBER ?");
	if (todo != null)
	{
		var newDiv ="<div style='cursor:pointer' class='sup' rel = '"+todo+"'>"+todo+"</div>";
		$('#ft_list').append(newDiv);
		list.push(todo);
	}
	$.cookie("cook", list);
});

