<?php
session_start();
$file = file_get_contents("private/passwd.csv");
$var = unserialize($file);
if (isset($_GET['power']))
{
	for ($i = 0; $i < count($var); $i++)
	{
		if ($var[$i]['login'] === $_POST['login'])
		{
			$var[$i]['admin'] = 1;
			$check = 1;
		}
	}
	if ($check !== 1)
	{
		header("Location: my_account.php?no_account_admin_power");
		return ;
	}
	file_put_contents("private/passwd.csv", serialize($var));
	header("Location: my_account.php?account_admin_power");
}
if (isset($_GET['nopower']))
{
	for ($i = 0; $i < count($var); $i++)
	{
		if ($var[$i]['login'] === $_POST['login'])
		{
			$var[$i]['admin'] = 0;
			$check = 1;
		}
	}
	if ($check !== 1)
	{
		header("Location: my_account.php?no_account_admin_nopower");
		return ;
	}
	file_put_contents("private/passwd.csv", serialize($var));
	header("Location: my_account.php?account_admin_nopower");
}
?>