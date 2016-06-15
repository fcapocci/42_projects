<?PHP

function ft_is_sort($tab)
{
	$i = 0;
	$tab2 = $tab;
	sort($tab2);
	while ($i < count($tab))
	{
		if (strcmp($tab[$i], $tab2[$i]) != 0)
			return (0);
		$i++;
	}
	return (1);
}

?>