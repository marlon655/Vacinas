<form method="post">
<?php
	if(isset($_POST['acao'])){
		$cpf = $_POST['cpf'];
		if ($cpf == '') {
			Painel::message('atencao','Insira um CPF ou Código que deseja deletar!');
		}else{
			$user = new Usuario();
			$user->deletar($cpf);
		}
	}
?>
		<div class="form-group">
			<span>Insira o CPF ou Código a ser deletado!</span>
			<label>CPF:</label>
			<input type="text" name="cpf">
		</div><!-- form-group -->
		<input type="submit" name="acao" value="Excluir!">
</form>