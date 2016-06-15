#!/usr/bin/php
<?PHP

if ($argc == 4)
{
	if (trim($argv[2]) == "+")
		$res = $argv[1] + $argv[3];
	if (trim($argv[2]) == "-")
		$res = $argv[1] - $argv[3];
	if (trim($argv[2]) == "*")
		$res = $argv[1] * $argv[3];
	if (trim($argv[2]) == "/")
		$res = $argv[1] / $argv[3];
	if (trim($argv[2]) == "%")
		$res = $argv[1] % $argv[3];
	echo $res."\n";
}
else
	echo "Incorrect Parameters\n";

?>