<?php
	if(!isset($_GET['id'])){
		Painel::message('erro','O Usuario não existe.');
		die();
	}else{
		$id = (int)$_GET['id'];
		$dados = new Usuario();
		$listar = $dados->listar($id);
	}
?>
<form method="post">
	<?php
		if (isset($_POST['acao'])) {
			$nome = $_POST['nome'];
			$cpf = $_POST['cpf'];
			$vacina = $_POST['vacina'];
			$data = $_POST['data'];
			$lote = $_POST['lote'];

			$user = new Usuario();
			$user->editar($nome,$cpf,$vacina,$data,$lote,$id);
		}
	?>
		<div class="form-group">
			<span>Editando: <?php echo $listar['nome'];?></span>
		</div>	
		<div class="form-group">
			<label>Nome:</label>
			<input type="text" name="nome" value="<?php echo $listar['nome'];?>">
		</div><!-- form-group -->
		
		<div class="form-group">
			<label>CPF:</label>
			<input type="text" name="cpf" value="<?php echo $listar['cpf'];?>">
		</div><!-- form-group -->
		
		<div class="form-group">
			<label>Vacina:</label>
			<input type="text" name="vacina" value="<?php echo $listar['vacina'];?>">
		</div><!-- form-group -->

		<div class="form-group">
			<label>Data:</label>
			<input type="text" name="data" value="<?php echo $listar['data'];?>">
		</div><!-- form-group -->

		<div class="form-group">
			<label>Lote:</label>
			<input type="text" name="lote" value="<?php echo $listar['lote'];?>">
		</div><!-- form-group -->
		<input type="submit" name="acao" value="Editar!">
</form>