<?php
include ("auth.php");
session_start();
if (empty($_GET['login']) || empty($_GET['passwd']))
	header("Location:index.php?error=1");
if ($_GET['login'] && $_GET['passwd'])
{
	if ((auth($_GET['login'], $_GET['passwd']) == TRUE))
	{
		$_SESSION['loggued_on_user'] = $_GET['login'];
		header("Location: index.php?home");
	}
	else
		header("Location:index.php?error=1");
}
?>