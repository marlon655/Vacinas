<?php
	class Painel
	{
		Public static function logado(){
			return isset($_SESSION['logado']) ? true : false;
		}
		Public static function loadPage(){
			if(isset($_GET['url'])){
				$url = explode('/',$_GET['url']);
				if (file_exists('pages/'.$url[0].'.php')) {
					include ('pages/'.$url[0].'.php');
				}else{
					header('location:' .INCLUDE_PATH_PAINEL);
				}
			}else{
				// include('pages/home.php');
			}
		}
		
		Public static function message($tipo,$menssagem){
			if($tipo == 'sucesso'){
				echo '<div class="box-alert sucesso">'.$menssagem.'</div>';
			}else if($tipo == 'erro'){
				echo '<div class="box-alert erro">'.$menssagem.'</div>';
			}else{
				echo '<div class="box-alert atencao">'.$menssagem.'</div>';
			}
		}

	}
?> 