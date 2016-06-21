<?php
session_start();
if ($_SESSION['loggued_on_user'])
{
	header("Location:index.php?panier=1&log");	
}
else
	header("Location:index.php?panier=1&notlog");
?>