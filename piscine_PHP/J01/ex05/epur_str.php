#!/usr/bin/php
<?PHP

function ft_split($str)
{
	$i = 0;
	$tab;
	$tmp = explode(" ", $str);
	foreach ($tmp as $elem)
	{
		if ($elem)
		{
			$tab[$i] = $elem;
			$i++;
		}
	}
	return ($tab);
}

if ($argc == 2)
{
	$tab = ft_split($argv[1]);
	$new = implode(" ", $tab);
	echo $new."\n";
}

?>