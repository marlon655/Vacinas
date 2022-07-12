<!DOCTYPE html>
<html>
<head>
	<title>Página de login</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0" />
	<link rel="stylesheet" href="<?php echo INCLUDE_PATH_PAINEL?>css/style.css" />
</head>
<body>
	<div class="box">
		<form method="post">
			<?php
				if (isset($_POST['acao'])) {
					$nome = $_POST['login'];
					$senha = $_POST['senha'];

					$user = new Usuario();
					$user->login($nome,$senha);
				}
			?>
			<h2>Acessar painel de controle</h2>
			<div class="box-wraper">
				<input type="text" name="login">
				<input type="password" name="senha">
				<input type="submit" name="acao">
			</div><!-- box-wraper -->
		</form>
	</div><!-- box -->

</body>
</html>