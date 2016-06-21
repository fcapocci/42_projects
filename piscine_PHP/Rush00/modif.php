<?php
session_start();
if (empty($_POST["login"]) || empty($_POST["oldpw"]) || empty($_POST["newpw"]) || isset($_POST["submit"]) != "OK")
{
	header("Location:my_account.php?error=4");
	session_destroy();
	return ;
}
$newpw = hash("Whirlpool", $_POST['newpw']);
$oldpw = hash("Whirlpool", $_POST['oldpw']);
$file = file_get_contents("private/passwd.csv");
$users = unserialize($file);
for ($i = 0; $i < count($users); $i++)
{
	if ($users[$i]['login'] === $_POST['login'])
	{
		if ($users[$i]['passwd'] === $oldpw)
		{
			$users[$i]['passwd'] = $newpw;
			$check_new_pw = 1;
		}
		else
		{
			header("Location:my_account.php?error=5");
			session_destroy();
			return ;
		}

	}
}
if ($check_new_pw === 1)
{
	file_put_contents("private/passwd.csv", serialize($users));
	header("Location: index.php");
}
else
{
	header("Location:my_account.php?error=5");
	session_destroy();
}	
?>