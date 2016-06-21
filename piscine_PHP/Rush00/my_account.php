<?php
	session_start();
	function check($login)
	{
		$file = file_get_contents("private/passwd.csv");
		$var = unserialize($file);
		$hash = hash("Whirlpool", $passwd);
		for ($i = 0; $i < count($var); $i++)
		{
			if ($var[$i]['login'] === $login)
			{
				if ($var[$i]['admin'] == 1)
					return TRUE;
			}
		}
	}
?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
		
		<!--[if lt IE 9]>
    	<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->
		
		<script type="text/javascript" src="menu.js"></script>

		<style media="screen">
		body { background-color: #4d394b; }
		.form { text-align: center; text-decoration: underline; font-size: 1.5em; }
		input { background-color: #D8D8D8;}
		label { display: block; width: 200px; float: left; margin-left: 20%; }
		section { border: 2px solid white; margin:auto; width: 50%; padding: 10%; border-radius: 10px; background-color: white; }
		h1 { text-align: center; text-decoration: underline; color: red;}
		p { text-align: center; }
		</style>
		
		<body>
		<section>
		<a href="index.php?home"> RETOUR À L'ACCEUIL </a>
		<?php
		if (check($_SESSION['loggued_on_user']) == TRUE)
		{
		?>
			<h1> GESTION SUPER USER </h1>
			<p class="form"> Supprimer un compte. </p>
			<form method='post' action='del.php?login=1'>
				<label for="Login"> Login a supprimer: </label> <input type='text' name='login'/>
				<input type='submit' name="submit" value='OK'/>
			</form>
			<?php
			if (isset($_GET['account_deleted']))
			{
			?>
				<p> <strong> Le compte a été surprimé. </strong> </p>
			<?php
			}
			?>
			<?php
			if (isset($_GET['no_account']))
			{
			?>
				<p> <strong> Pas de compte associé. </strong> </p>
			<?php
			}
			?>
			<p class="form"> Donner un droit admin à un utilisateur. </p>
			<form method='post' action='droit.php?power'>
				<label for="Login"> Login : </label> <input type='text' name='login'/>
				<input type='submit' name="submit" value='OK'/>
			</form>
			<?php
			if (isset($_GET['account_admin_power']))
			{
			?>
				<p> <strong> Le compte a maintenant un droit admin. </strong> </p>
			<?php
			}
			?>
			<?php
			if (isset($_GET['no_account_admin_power']))
			{
			?>
				<p> <strong> Pas de compte associé. </strong> </p>
			<?php
			}
			?>
			<p class="form"> Retirer un droit admin à un utilisateur. </p>
			<form method='post' action='droit.php?nopower'>
				<label for="Login"> Login : </label> <input type='text' name='login'/>
				<input type='submit' name="submit" value='OK'/>
			</form>
			<?php
			if (isset($_GET['account_admin_nopower']))
			{
			?>
				<p> <strong> Le compte a maintenant un droit admin. </strong> </p>
			<?php
			}
			?>
			<?php
			if (isset($_GET['no_account_admin_nopower']))
			{
			?>
				<p> <strong> Pas de compte associé. </strong> </p>
			<?php
			}
			?>
			<br /> <br />
		<?php
		}
		?>
		<p class="form"> Modifier mot de passe :</p>
		<form method='post' action='modif.php'>
			<label for="Login"> Login: </label> <input type='text' name='login'/>
			<br />
			<label for="Login"> Ancien mot de passe: </label> <input type='password' name='oldpw'/>
			<br />
			<label for="Login"> Nouveau mot de passe: </label> <input type='password' name='newpw'/>
			<input type='submit' name="submit" value='OK'/>
		</form>
		<br /> <br /> <br /> <br />
		<a href="del.php">
			<input type="submit" class="myButton" name="" value="Supprimer mon compte" style="margin-left: 35%;">
		</a>
		</section>
		</body>
	</head>
</html>