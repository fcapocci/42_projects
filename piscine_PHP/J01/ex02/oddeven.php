#!/usr/bin/php
<?PHP

while (1 > 0)
{
	echo "Entrez un nombre: ";
	if (feof(STDIN) == TRUE)
	{
		echo "^D\n";
		exit (0);
	}
	$line = trim(fgets(STDIN));
	if (is_numeric($line) == FALSE)
		echo "'",$line, "'", "n'est pas un chiffre\n";
	else if ($line % 2 == 0)
		echo "Le chiffre ", $line," est Pair\n";
	else
		echo "Le chiffre ", $line," est Impair\n";
}

?>