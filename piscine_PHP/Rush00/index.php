<?php
session_start();
if (empty($_GET))
{ 
	header("Location: index.php?home");
}
?>
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
					<li><a href="index.php?alcool=1"> Alcool </a></li>
					<li><a href="index.php?snacks=1"> Snacks </a></li>
					<li><a href="index.php?all_products=1">Voir tous les produits</a></li>
				</ul>
			</li>
			<li><a href="index.php?panier=1">Mon panier</a></li>
		</ul>
			<?php
   			if(!isset($_SESSION['loggued_on_user']))
   			{      
			?>
				<span id="logform">
					<form action="login.php" methode="POST">
						<input id="logbarre" type="text" name="login" placeholder="LOGIN"/>
						<input id="logbarre" type="password" name="passwd" placeholder="PASSWORD"/>
						<input id="button" type="submit" name="submit" value="OK" />
						<a id="no_inscript" href="inscription.php">s'inscrire ?</a>
					</form>
				</span>
				<?php
				if (isset($_GET['error']) && $_GET['error'] == 1)
				{
				?>
				<span id="logform">
					<span class="error1"> <bold> Pas de login ou MDP. </bold> </span>
				</span>
				<?php
				}
				?>
			<?php
   			}
   			else
   			{
			?>
		   		<span id="logform">
		      		Bonjour <a href="my_account.php"><?php echo $_SESSION['loggued_on_user']; ?> </a>  
		       		<a href="logout.php">
		           		<input type="submit" class="myButton" name="" value="Se deconnecter" style="margin-left:15px;">
		       		</a>
		       </span>
			<?php
   			}
			?>
		</header>

		<section>
			<?php
			if (isset($_GET['panier']) && $_GET['panier'] == 1 && !isset($_GET['log']))
			{
			?>

			<?php
				include("app_panier.php");
				$erreur = false;

				$action = (isset($_POST['action'])? $_POST['action']:  (isset($_GET['action'])? $_GET['action']:null )) ;
				if($action !== null)
				{
				   if(!in_array($action,array('ajout', 'suppression', 'refresh')))
				   $erreur=true;

				   //récuperation des variables en POST ou GET
				   $l = (isset($_POST['l'])? $_POST['l']:  (isset($_GET['l'])? $_GET['l']:null )) ;
				   $p = (isset($_POST['p'])? $_POST['p']:  (isset($_GET['p'])? $_GET['p']:null )) ;
				   $q = (isset($_POST['q'])? $_POST['q']:  (isset($_GET['q'])? $_GET['q']:null )) ;

				   //Suppression des espaces verticaux
				   $l = preg_replace('#\v#', '',$l);
				   //On verifie que $p soit un float
				   $p = floatval($p);

				   //On traite $q qui peut etre un entier simple ou un tableau d'entier
				    
				   if (is_array($q)){
				      $QteArticle = array();
				      $i=0;
				      foreach ($q as $contenu){
				         $QteArticle[$i++] = intval($contenu);
				      }
				   }
				   else
				   $q = intval($q);
				    
				}
				if (!$erreur)
				{
				   switch($action)
				   {
				      Case "ajout":
				         ajouterArticle($l,$q,$p);
				         break;

				      Case "suppression":
				         supprimerArticle($l);
				         break;

				      Case "refresh" :
				         for ($i = 0 ; $i < count($QteArticle) ; $i++)
				         {
				            modifierQTeArticle($_SESSION['panier']['libelleProduit'][$i],round($QteArticle[$i]));
				         }
				         break;

				      Default:
				         break;
				   }
				}
			?>
			<a href="index.php?home"> CONTINUER VOS ACHATS </a>
			<br /> <br /> <br />
			<form method="post" action="index.php?panier=1">
					<center> <table id="shop">
						<tr>
							<td colspan="4">Votre panier</td>
						</tr>
						<tr>
							<td>Libellé</td>
							<td>Quantité</td>
							<td>Prix Unitaire</td>
							<td>Action</td>
						</tr>
			<?php
				if (creationPanier())
				{
				   $nbArticles=count($_SESSION['panier']['libelleProduit']);
				   if ($nbArticles <= 0)
				   echo "<tr> <td colspan='4' style='color: red'> Votre panier est vide </td> </tr>";
				   else
				   {
				      for ($i=0 ;$i < $nbArticles ; $i++)
				      {
				         echo "<tr>";
				         echo "<td>".htmlspecialchars($_SESSION['panier']['libelleProduit'][$i])."</ td>";
				         echo "<td><input type=\"text\" size=\"4\" name=\"q[]\" value=\"".htmlspecialchars($_SESSION['panier']['qteProduit'][$i])."\"/></td>";
				         echo "<td>".htmlspecialchars($_SESSION['panier']['prixProduit'][$i])."</td>";
				         echo "<td><a href=\"".htmlspecialchars("index.php?panier=1&action=suppression&l=".rawurlencode($_SESSION['panier']['libelleProduit'][$i]))."\">Supprimer</a></td>";
				         echo "</tr>";
				      }

				      echo "<tr><td colspan=\"2\"> </td>";
				      echo "<td colspan=\"2\">";
				      echo "Total : ".MontantGlobal();
				      echo "</td></tr>";

				      echo "<tr><td colspan=\"4\">";
				      echo "<input type=\"submit\" value=\"Rafraichir\"/>";
				      echo "<input type=\"hidden\" name=\"action\" value=\"refresh\"/>";

				      echo "</td></tr>";
				   }
				}
			?>
				</table> </center>
			</form>
			<br />
			<form action="valid.php" method="POST" onSubmit="Voulez vous vraiment valider ?">
			   <input name="valid_cmd" type="submit" value="Valider ma commande" style="display: block; margin: auto;" />
			</form>
			<?php
				if (isset($_GET['notlog']))
				{
				?>
					<p style="text-align: center; color: red; font-size: 2em;"> Vous devez vous inscrire pour valider votre commande. </p>
					<p style="text-align: center;"> <a href="inscription.php"> S'inscrire </a> </p>
					<p style="text-align: center;"> Se Connecter </p>
					<form action="login.php" methode="POST" style="text-align: center">
						<input id="logbarre" type="text" name="login" placeholder="LOGIN"/>
						<input id="logbarre" type="password" name="passwd" placeholder="PASSWORD"/>
						<input id="button" type="submit" name="submit" value="OK" />
					</form>
				<?php
				}
				?>
			<?php
			}
			else if (isset($_GET['log']) && count($_SESSION['panier']['libelleProduit']) > 0)
			{
			?>
				<p style="text-align: center;"> VOTRE COMMADE A BIEN ETE TRAITE </p>
				<p style="text-align: center;"> <a href="index.php?home"> Revenir à la page d'acceuil. </a> </p>
			<?php
			}
			else if (isset($_GET['log']) && count($_SESSION['panier']['libelleProduit']) <= 0)
			{
			?>
				<p style="text-align: center;"> VOUS N'AVEZ PAS D'ARTICLES </p>
				<p style="text-align: center;"> <a href="index.php?panier=1"> Revenir au panier. </a> </p>
			<?php
			}
			?>
			<?php
			if (isset($_GET['home']) || isset($_GET['boisson']) || isset($_GET['snacks']) || isset($_GET['alcool']) || isset($_GET['all_products']))
			{
			?>
			<table>
			<tr>
			<?php
				$fd = fopen("article.csv", 'r');
				$i = 0;
				while (($produit = fgetcsv($fd, 0, ';')))
				{
					$info = explode(":", $produit[0]);
					$i++;
					$nom = explode('=', $info[0]);
					$cat = explode('=', $info[1]);
					$prix = explode('=', $info[2]);
					if (isset($_GET['alcool']))
					{
						if ($cat[1] === "alcool")
						{
					?>
						<td> <img src="img/<?php echo $cat[1];?>/<?php echo $nom[1];?>.jpg" width="100" height="100"> </td>
					<?php
						}
					} 
					else if (isset($_GET['snacks']))
					{
						if ($cat[1] === "gateau")
						{
					?>
						<td> <img src="img/<?php echo $cat[1];?>/<?php echo $nom[1];?>.jpg" width="100" height="100"> </td>
					<?php
						}
					}
					else if (isset($_GET['boisson']))
					{
						if ($cat[1] === "boisson")
						{
					?>
						<td> <img src="img/<?php echo $cat[1];?>/<?php echo $nom[1];?>.jpg" width="100" height="100"> </td>
					<?php
						}
					}
					else
					{
					?>
						<td> <img src="img/<?php echo $cat[1];?>/<?php echo $nom[1];?>.jpg" width="100" height="100"> </td>
					<?php
					}
					if ($i === 7 )
						break;
				}
				fclose($fd);
				?>
				</tr>
				<tr>
				<?php
				$fd = fopen("article.csv", 'r');
				$i = 0;
				while (($produit = fgetcsv($fd, 0, ';')))
				{
					$info = explode(":", $produit[0]);
					$i++;
					$nom = explode('=', $info[0]);
					$cat = explode('=', $info[1]);
					$prix = explode('=', $info[2]);
					if (isset($_GET['snacks']))
					{
						if ($cat[1] === "gateau")
						{
					?>
					<td> <?php echo $nom[1];?> <a href="index.php?panier=1&amp;action=ajout&amp;l=<?php echo $nom[1];?>&amp;q=0&amp;p=<?php echo $prix[1];?>"><img src="img/caddie.gif" width="20" height="20"> </a> </td>
					<?php
						}
					}
					else if (isset($_GET['alcool']))
					{
						if ($cat[1] === "alcool")
						{
					?>
					<td> <?php echo $nom[1];?> <a href="index.php?panier=1&amp;action=ajout&amp;l=<?php echo $nom[1];?>&amp;q=0&amp;p=<?php echo $prix[1];?>"><img src="img/caddie.gif" width="20" height="20"> </a> </td>
					<?php
						}
					} 
					else if (isset($_GET['boisson']))
					{
						if ($cat[1] === "boisson")
						{
					?>
					<td> <?php echo $nom[1];?> <a href="index.php?panier=1&amp;action=ajout&amp;l=<?php echo $nom[1];?>&amp;q=0&amp;p=<?php echo $prix[1];?>"><img src="img/caddie.gif" width="20" height="20"> </a> </td>
					<?php 
						}
					}
						else
					{
					?>
					<td> <?php echo $nom[1];?> <a href="index.php?panier=1&amp;action=ajout&amp;l=<?php echo $nom[1];?>&amp;q=0&amp;p=<?php echo $prix[1];?>"><img src="img/caddie.gif" width="20" height="20"> </a> </td>
					<?php 
				}
					if ($i === 7 )
						break;
				}
				fclose($fd);
				?>
				</tr>
			</table>
			<?php
			}
			?>
		</section>
	</body>
</html>