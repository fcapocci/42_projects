<?php
session_start();
$file = file_get_contents("private/passwd.csv");
$var = unserialize($file);
$hash = hash("Whirlpool", $passwd);
if (isset($_GET['login']))
{
	for ($i = 0; $i < count($var); $i++)
	{
		if ($var[$i]['login'] === $_POST['login'])
		{
			$var[$i]['login'] = "";
			$var[$i]['passwd'] = "";
			file_put_contents("private/passwd.csv", serialize($var));
			header("Location: my_account.php?account_deleted");
			$check = 1;
			return ;
		}
	}
	if ($check !== 1)
	{
		header("Location: my_account.php?no_account");
		return ;
	}
}
for ($i = 0; $i < count($var); $i++)
{
	if ($var[$i]['login'] === $_SESSION['loggued_on_user'])
	{
		$var[$i]['login'] = "";
		$var[$i]['passwd'] = "";
	}
}
file_put_contents("private/passwd.csv", serialize($var));
session_destroy();
header("Location: index.php");
?>