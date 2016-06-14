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
	sort($tab);
	return ($tab);
}

$i = 1;
$j = 0;

if ($argc > 1)
	while ($i < $argc)
	{
		$tab = ft_split($argv[$i]);
		foreach ($tab as $elem)
			$res[$j++] = $elem;
		$i++;
	}
	sort($res);
	foreach ($res as $elem)
		echo $elem,"\n";

?>