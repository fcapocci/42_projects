#!/usr/bin/php
<?PHP

$i = 1;

if ($argc > 1)
	while ($i < $argc)
		echo $argv[$i++],"\n";

?>