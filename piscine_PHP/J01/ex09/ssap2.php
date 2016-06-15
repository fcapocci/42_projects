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
$res;
$res1;
$res2;
$res3;

if ($argc > 1)
{
	while ($i < $argc)
	{
		$tab = ft_split($argv[$i]);
		foreach ($tab as $elem)
			if (is_numeric($elem) == TRUE)
				$res1[] = $elem;
			else if(ctype_alpha($elem) == TRUE)
				$res2[] = $elem;
			else
				$res3[] = $elem;
		$i++;
	}
	sort($res1, SORT_STRING | SORT_FLAG_CASE);
	sort($res2, SORT_STRING | SORT_FLAG_CASE);
	sort($res3, SORT_STRING | SORT_FLAG_CASE);
	$res = array_merge($res2, $res1, $res3);
	foreach ($res as $elem)
		echo $elem,"\n";
}

?>