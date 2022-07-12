<?php
 if (isset($_GET['sair'])) {
 		session_destroy();
		header('location:' .INCLUDE_PATH_PAINEL);
 }
?>
<!DOCTYPE html>
<html>
<head>
	<title>Vacinação</title>
	<link rel="stylesheet" type="text/css" href="css/style.css">
	<meta name="viewport" content="width=device-width,initial-scale=1.0,maximum-scale=1.0">
	<meta charset="utf-8">
</head>
<body>
	<div class="header">
		<div class="icon">
			<h2><<</h2>
		</div><!-- icon -->
		<div class="sair">
			<a href="<?php INCLUDE_PATH_PAINEL?>?sair">Sair</a>
		</div><!-- sair -->
	</div>
	<div class="clear"></div>

	<div class="menu">
		<div class="user">
			<div class="user-img">
				<div class="img"></div>
			</div><!-- user-img -->
			<h2>Admin</h2>
			<span>Administrador</span>
		</div><!--user-->
	
		<div class="submenu">
			<div class="submenu-item">
			<h2>Menu</h2>
			<a href="<?php echo INCLUDE_PATH_PAINEL?>cadastrar">Cadastrar</a>
			<a href="<?php echo INCLUDE_PATH_PAINEL?>listar">Listar</a>
			<a href="<?php echo INCLUDE_PATH_PAINEL?>excluir">Excluir</a>
			</div>
		</div><!-- sub-menu -->
	</div><!-- menu -->
	<div class="clear"></div>

	<div class="content">
		<?php
			Painel::loadPage();
		 ?>
	</div><!-- content -->
	<div class="clear"></div>

	<script src="<?php 	echo INCLUDE_PATH_PAINEL?>js/script.js"></script>
</body>
</html>