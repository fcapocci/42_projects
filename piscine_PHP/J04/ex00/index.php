<?php

session_start();
if($_GET["login"] !== FALSE && $_GET["passwd"] !== FALSE)
{
	if($_GET["submit"] === "OK")
	$_SESSION["login"] = $_GET["login"];
	$_SESSION["passwd"] = $_GET["passwd"];
}

?>
<html><body>
<form methode="GET" action="index.php">
	Identifiant: <input type="text" name="login" value="<?php if($_SESSION["login"] !== FALSE) { echo $_SESSION["login"]; } ?>" />
	<br />
	Mot de passe: <input type="password" name="passwd" value="<?php if($_SESSION["passwd"] !== FALSE) { echo $_SESSION["passwd"]; } ?>" />
	<input type="submit" name="submit" value="OK" />
</form>
</body></html>
