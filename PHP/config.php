<?php
	session_start();
	date_default_timezone_set('America/Sao_Paulo');

	$autoload = function($class){
		include('classes/'.$class.'.php');
	};
	spl_autoload_register($autoload);

	define('INCLUDE_PATH', 'http://localhost/PHP/');
	define('INCLUDE_PATH_PAINEL', INCLUDE_PATH.'painel/');
//--Configurações do DB--//
	define('HOST', 'localhost');
	define('USER', 'root');
	define('PASSWORD', '');
	define('DATABASE', 'vacinas');
	define('BASE_DIR_PAINEL', __DIR__.'/painel');

?>