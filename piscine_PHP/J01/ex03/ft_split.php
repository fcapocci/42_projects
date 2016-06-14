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

?>