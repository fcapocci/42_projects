#!/usr/bin/php
<?PHP

function ft_split($str)
{
	$i = 0;
	$tab;
	$tmp2;
	$tmp = explode(" ", $str);
	foreach ($tmp as $elem)
	{
		if ($elem)
		{
			$tab[$i] = $elem;
			$i++;
		}
	}
	$tmp2 = $tab[$i];
	$tab[$i] = $tab[0];
	$tab[0] = $tmp2;
	return ($tab);
}

if ($argc > 1)
{
	$tab = ft_split($argv[1]);
	$new = implode(" ", $tab);
	$new = trim($new);
	echo $new."\n";
}

?>