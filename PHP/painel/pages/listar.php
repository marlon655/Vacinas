<?php
	$sql = new Usuario();
	$dados = $sql->listar();
?>
<?php
	foreach ($dados as $key => $value) {
?>
		<div class="form-group divisor" style="margin: 10px 5px;">
			<span><b>Código:</b><?php echo $value['codigo']?></span>
			<span>Nome: <?php echo $value['nome']?></span>
			<span>Vacina: <?php echo $value['vacina']?></span>
			<span>CPF: <?php echo $value['cpf']?></span>
			<span>Data: <?php echo $value['data']?></span>
			<span>Lote: <?php echo $value['lote']?></span>
			<div class="buttom">
				<a href="<?php echo INCLUDE_PATH_PAINEL ?>editar-vacinado?id=<?php echo $value['id']?>"><span>Editar</span></a>
			</div>
		</div><!-- form-group -->
<?php }?>