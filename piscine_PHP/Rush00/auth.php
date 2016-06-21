<?php
	function auth($login, $passwd)
	{
		if (file_exists("private") == FALSE)
		{
			header("Location: index.php");
			return ;
		}
		$file = file_get_contents("private/passwd.csv");
		$var = unserialize($file);
		$hash = hash("Whirlpool", $passwd);
		for ($i = 0; $i < count($var); $i++)
		{
			if ($var[$i]['login'] === $login)
			{
				if ($var[$i]['passwd'] === $hash)
					return TRUE;
				else
					return FALSE;
			}
		}
		return FALSE;
	}
?>