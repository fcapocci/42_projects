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

function is_alpha($str)
{
	$i = 0;
	while ($i < strlen($str))
	{
		if (($str[$i] >= 'a' && $str[$i] <= 'z') || ($str[$i] >= 'A' && $str[$i] <= 'Z'))
			$i++;
		else
			return (0);
	}
	return (1);
}

$i = 1;

if ($argc > 1)
{
	while ($i < $argc)
	{
		$tab = ft_split($argv[$i]);
		foreach ($tab as $elem)
			if (is_numeric($elem) == TRUE)
				$res1[] = $elem;
			else if (is_alpha($elem))
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