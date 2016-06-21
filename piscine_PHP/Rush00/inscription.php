<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<link rel="stylesheet" href="menu.css" />
		<title>Store</title>
	</head>
	<body>
	<header>
		<ul id="menu-bar">
			<li class="active"><a href="index.php?home">Home</a></li>
			<li><a href="#">Products</a>
				<ul>
					<li><a href="index.php?boisson=1"> Boissons </a></li>
					<li><a href="index.php?snacks=1"> Snacks </a></li>
					<li><a href="index.php?all_products=1">Voir tous les produits</a></li>
				</ul>
			</li>
			<li><a href="index.php?panier=1">Mon panier</a></li>
		</ul>
	</header>

	<section>
		<?php
		if (isset($_GET['error']) && $_GET['error'] == 2)
		{
		?>
			<p class="error2"> Pas de login ou MDP. </p>
		<?php
		}
		?>
		<?php
		if (isset($_GET['error']) && $_GET['error'] == 3)
		{
		?>
			<p class="error2"> Login ou MDP déjà existant. </p>
		<?php
		}
		?>
	    <form method="post" action="install.php" align="middle">
	      <input type="text" name="login" placeholder="login"/>
	      <input type="password" name="passwd" placeholder="password"/>
	      <input type="submit" name="submit" value="OK"/>
	    </form>
	</section>

	</body>
</html>