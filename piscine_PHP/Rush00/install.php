<?php
session_start();
if (empty($_POST["login"]) || empty($_POST["passwd"]) || isset($_POST["submit"]) != "OK")
{
	header("Location:inscription.php?error=2");
	session_destroy();
	return ;
}
$pw = hash("Whirlpool", $_POST['passwd']);
if (file_exists("private") == FALSE)
{
	$stock = array("login" => $_POST['login'], "passwd" => $pw, "admin" => 1);
	$users[] = $stock; 
	mkdir("private/", 0777, true);
	$file = file_put_contents("private/passwd.csv", serialize($users));
	$_SESSION['loggued_on_user'] = $_POST['login'];
	header("Location: index.php?home");
}
else
{
	$file = file_get_contents("private/passwd.csv");
	$users = unserialize($file);
	for ($i = 0; $i < count($users); $i++)
	{
		if ($users[$i]['login'] === $_POST['login'])
		{
			header("Location:inscription.php?error=3");
			session_destroy();
		}
	}
	$stock = array("login" => $_POST['login'], "passwd" => $pw, "admin" => 0);
	$users[] = $stock;
	file_put_contents("private/passwd.csv", serialize($users));
	$_SESSION['loggued_on_user'] = $_POST['login'];
	header("Location: index.php?home");
}
?>