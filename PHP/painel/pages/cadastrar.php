<form method="post">
	<?php
	if (isset($_POST['acao'])) {
		$nome = $_POST['nome'];
		$cpf = $_POST['cpf'];
		$vacina = $_POST['vacina'];
		$data = $_POST['data'];
		$lote= $_POST['lote'];

		if ($nome == '') {
			Painel::message('erro','O campo Nome está vazio!');
		}else if($cpf == ''){
			Painel::message('erro','O campo CPF está vazio!');
		}else if($vacina == ''){
			Painel::message('erro','O campo Vacina está vazio!');
		}else if($data == ''){
			Painel::message('erro','O campo Data está vazio!');
		}else if($lote == ''){
			Painel::message('erro','O campo Lote está vazio!');
		}else{
			$user = new Usuario();
			$user->cadastro($nome,$cpf,$vacina,$data,$lote);
		}
	}
	?>
		<div class="form-group">
			<label>Nome:</label>
			<input type="text" name="nome">
		</div><!-- form-group -->
		
		<div class="form-group">
			<label>CPF:</label>
			<input type="text" name="cpf">
		</div><!-- form-group -->
		
		<div class="form-group">
			<label>Vacina:</label>
			<input type="text" name="vacina">
		</div><!-- form-group -->

		<div class="form-group">
			<label>Data:</label>
			<input type="text" name="data">
		</div><!-- form-group -->

		<div class="form-group">
			<label>Lote:</label>
			<input type="text" name="lote">
		</div><!-- form-group -->
		<input type="submit" name="acao" value="Cadastrar!">
</form>