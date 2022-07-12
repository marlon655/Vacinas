<?php
	class Usuario
	{
		public function cadastro($nome,$cpf,$vacina,$data,$lote){
			$sql = Mysql::conectar()->prepare("SELECT * FROM vacinado");
			$sql->execute();
			$codigo = $sql->rowCount();

			$query = "nome = ? OR cpf = ?";
			$sql = Mysql::conectar()->prepare("SELECT * FROM `vacinado` WHERE $query");
			$sql->execute(array($nome,$cpf));
			$verifica = $sql->rowCount();

			if($verifica == 0){
				$sql = Mysql::conectar()->prepare("INSERT INTO `vacinado` VALUES(null,?,?,?,?,?,?) ");
				$sql->execute(array($nome,$codigo,$cpf,$vacina,$data,$lote));
				Painel::message('sucesso','Cadastrado com sucesso!');
			}else{
				Painel::message('atencao','Já existe um usuario com o mesmo CPF ou Nome!');
			}
		}

		public function deletar($par){
			$sql = Mysql::conectar()->prepare("SELECT * FROM `vacinado` WHERE cpf=? OR codigo=? ");
			$sql->execute(array($par,$par));
			$row = $sql->rowCount();
			if ($row == 0) {
				Painel::message('atencao','Insira um registro válido!');	
			}else{
				$sql = Mysql::conectar()->prepare("DELETE FROM `vacinado` WHERE cpf=? OR codigo=? ");
				$sql->execute(array($par,$par));
				Painel::message('sucesso','Registro deletado com sucesso!');	
			}
		}

		public function listar($par = ''){
			if($par == ''){
				$sql = Mysql::conectar()->prepare("SELECT * FROM `vacinado`");
				$sql->execute();
				return $sql->fetchAll();
			}else{
				$sql = Mysql::conectar()->prepare("SELECT * FROM `vacinado` WHERE id = ?");
				$sql->execute(array($par));
				return $sql->fetch();
			}
			
		}

		public function editar($nome,$cpf,$vacina,$data,$lote,$id){
			$sql = Mysql::conectar()->prepare("UPDATE `vacinado` SET nome=?, cpf=?, vacina=?, data=?, lote=? WHERE id = $id");
			$sql->execute(array($nome,$cpf,$vacina,$data,$lote));
			Painel::message('sucesso','Editado com sucesso!');
		}

		public function login($user,$password){
			$sql = Mysql::conectar()->prepare("SELECT * FROM `user` WHERE nome=? AND senha=?");
			$sql->execute(array($user,$password));

			if($sql->rowCount()== 1){
				$info = $sql->fetch();
				$_SESSION['logado'] = true;
				header('Location:'.INCLUDE_PATH_PAINEL);
			}else{
				Painel::message('erro','Usuario não Cadastrado');
			}
		}
	}