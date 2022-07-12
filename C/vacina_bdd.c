#include <stdio.h>
#include <winsock2.h>
#include <mysql.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

struct cadVac
{
	int codigo;
	char nome[30];
	char cpf[12];
	char vacinas[20];
	char data[10];
	float lote;
};

void buscar(MYSQL *conexao);
void cadastro(MYSQL *conexao);
void listagem(MYSQL *conexao);
void excluir(MYSQL *conexao);
void login(MYSQL *conexao);
void menu(MYSQL *conexao);
//---------------------------------------INDEX------------------------------------------------------//
void main()
{
    MYSQL *conexao=mysql_init(NULL); 
    //cria o endereço de memoria pra armazenar a conexao.
    MYSQL *conecta = mysql_real_connect(conexao, "127.0.0.1", "root", "", "vacinas", 0, NULL, 0);
	//se nao armazenar no endereço de memoria, funçao retorna nulo.
	if(conecta == NULL)
    {
        printf("Falha na conexao com o Banco de Dados\n");
        printf("Erro %d : %s\n", mysql_errno(conexao), mysql_error(conexao));
	}
	else
    {
    	login(conexao);
//		menu(conexao);
    }
}
//---------------------------------------LOGIN---------------------------------------------//
void login(MYSQL *conexao){
	MYSQL_RES *consulta;
	my_ulonglong num_linhas;

	char user;	
	char login[20];
	char senha[20];
	char query[1024];
	int log,pass;
	
	user = 'a';
	while(user == 'a'){		
	printf("Digite seu login:");
	scanf("%20[^\n]s",&login);
	fflush(stdin);
	printf("Digite sua senha:");
	scanf("%20[^\n]s",&senha);
	fflush(stdin);
	system("cls");
//----------PROTECAO-CONTRA-SQL-INJECTION--NO--INPUT----------------------------------------
	log = strncmp(login,"'",1);
	pass = strncmp(senha,"'",1);
//	printf("strcmp = %d \n",log);
//	printf("strcmp = %d \n",pass);
	
//--------------------------------------------------------------------------------------------
	while((log == 0) || (pass == 0)){
		printf("Digite Login e senha correto!!\n");
		printf("Digite seu login:");
		scanf("%20[^\n]s",&login);
		fflush(stdin);

		printf("Digite sua senha:");
		scanf("%20[^\n]s",&senha);
		fflush(stdin);
		system("cls");
		
		log = strncmp(login,"'",1);
		pass = strncmp(senha,"'",1);
	}
//----------------------------------------------------------------------------------------------
	sprintf(query,"SELECT * FROM user WHERE nome = '%s' AND senha = '%s'",login,senha);
	if(mysql_query(conexao,query))//retorna 1 se não houver conexao, ou 0 se conectar.
			printf("\nNão foi possível executar a instrução\nERRO: %s\n", mysql_error(conexao));
		else
		{	
			consulta = mysql_store_result(conexao);
			num_linhas = mysql_num_rows(consulta);
			if(num_linhas == 0)
			{
				
				printf("Login ou Senha Incorretos!\n");
			}
			else
			{
				user = 'b';
				menu(conexao);
			}
			mysql_free_result(consulta);	
		}
	}
}	

//---------------------------------------MENU-------------------------------------------------------//
void menu(MYSQL *conexao)
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	char resp;
	resp = 's';
	
	while(resp == 's')
	{
		printf("O que deseja fazer agora?Escolha uma opção.\n");
		printf("1 - Cadastrar vacina.\n");
		printf("2 - Listar todas aplicações.\n");
		printf("3 - Consultar CPF.\n");
		printf("4 - Excluir paciente.\n");
		printf("5 - Sair.\n");
		scanf("%d",&opcao);
		fflush(stdin);
		
		system("cls");
		 
		switch(opcao)
		{
			case 1:
				cadastro(conexao);
			break;
			case 2:
				listagem(conexao);
			break;
			case 3:
				buscar(conexao);
			break;
			case 4:
				excluir(conexao);
			break;
			case 5:
				resp = sair();
			break;
			default:
				printf("\n opção invalida \n\n");
				system("pause");
				system("cls");
		}	
	}
}
//------------------------------------ CADASTRO -----------------------------------------------------//
void cadastro(MYSQL *conexao){
	struct cadVac vacina;
	char reg,query[1024];
	MYSQL_RES *consulta;
	my_ulonglong num_linhas;
	reg = 's';
	while(reg == 's')
	{
		if(mysql_query(conexao,"SELECT * FROM vacinado"))//retorna 1 se não houver conexao, ou 0 se conectar.
			printf("\nNão foi possível executar a instrução\nERRO: %s\n", mysql_error(conexao));
		else
		{	
			consulta = mysql_store_result(conexao);
			num_linhas = mysql_num_rows(consulta);
			if(num_linhas == 0)
			{
				vacina.codigo = 0;
			}
			else
			{
				vacina.codigo = num_linhas;
			}
			mysql_free_result(consulta);	
		}
		fflush(stdin);

		printf("Nome completo:\n");
		scanf("%30[^\n]s",&vacina.nome);
		fflush(stdin);

		printf("Numero do CPF (sem ponto e sem traço):\n");
		gets(vacina.cpf);
		if(tamanho(vacina.cpf)!= 11)
		{
			while(tamanho(vacina.cpf)!= 11)
			{
				printf("Erro - O CPF deve conter 11 Digitos.\n");
				printf("Numero do CPF(sem ponto e sem traço):\n");
				gets(vacina.cpf);
				fflush(stdin);							
			}
		}
		fflush(stdin);
		
		printf("Nome da vacina aplicada:\n");
		scanf("%20[^\n]s",&vacina.vacinas);
		fflush(stdin);
					
		printf("Data de aplicacao:\n");
		scanf("%10[^\n]s",&vacina.data);
		fflush(stdin);
					
		printf("numero do lote:\n");
		scanf("%f",&vacina.lote);
		fflush(stdin);
				
		sprintf(query,"INSERT INTO vacinado (nome,codigo,cpf,vacina,data,lote) VALUES ('%s','%d','%s','%s','%s','%f')",
		vacina.nome,vacina.codigo,vacina.cpf,vacina.vacinas,vacina.data,vacina.lote);
					
		if(mysql_query(conexao,query)){
			printf("\nNão foi possível executar a inserção\nERRO: %s\n", mysql_error(conexao));
		}
		else
		{
			system("cls");
       		printf("A vacina foi cadastrada com sucesso!\n");
		}
		printf("Fazer um novo registro? s/n\n");
		scanf(" %c",&reg);
		fflush(stdin);
		system("cls");
	}
}
//------------------------------------LISTA---------------------------------------------------------//
void listagem(MYSQL *conexao){
	MYSQL_RES *consulta;
	MYSQL_ROW  rs_linhas;
	MYSQL_FIELD *rs_colunas;
	my_ulonglong num_linhas;

	if(mysql_query(conexao,"SELECT * FROM vacinado"))
		printf("Erro: %s\n",mysql_error(conexao));
	else{
		consulta = mysql_store_result(conexao);
		num_linhas = mysql_num_rows(consulta);	
	//verifica se existe pelo menos uma pessoa cadastrada.
	if(!num_linhas == 0)
	{
		while((rs_linhas = mysql_fetch_row(consulta))!= NULL){
			printf("codigo: %s \n",rs_linhas[2]);
			printf("nome: %s \n",rs_linhas[1]);
			printf("cpf: ");
			formatar("000.000.000-00",rs_linhas[3]);
			printf("vacina: %s \n",rs_linhas[4]);
			printf("data: %s \n",rs_linhas[5]);
			printf("numero do lote: %s \n",rs_linhas[6]);	
			printf("-----------------------------------------------------\n\n");
		}
	}
	else
	{
		printf("nao exite nenhum registro!\n\n");
	}
	mysql_free_result(consulta);
	system("PAUSE");
	system("cls");
	}

}
//----------------------------------------BUSCA------------------------------------------------------//
void buscar(MYSQL *conexao){
	my_ulonglong num_linhas;
	MYSQL_ROW rs_linhas;
	MYSQL_RES *consulta;

	int acha;
	char busca,buscar,query[1024],cpfbusca[12];
	
	busca = 's';
		while (busca == 's')
		{
			printf("Digite o CPF (sem ponto e sem traço) para busca: \n");
			scanf("%s",&cpfbusca);
			fflush(stdin);
			system("cls");
			
			sprintf(query,"SELECT * FROM vacinado WHERE vacinado.cpf= %s",cpfbusca);
			if(mysql_query(conexao,query))
				printf("Tipo de Erro: %s\n",mysql_error(conexao));
			else
			{	
				consulta = mysql_store_result(conexao);//armazena todo resultado de mysql_query();	
				num_linhas = mysql_num_rows(consulta);//retorna quantidade de linhas feita pela consulta.
				rs_linhas = mysql_fetch_row(consulta);//a cada chamada retorna a linha referente a consulta como um array.
				if(!num_linhas == 0)
				{
					acha=1;
				}
				else
				{
					acha=0;	
				}	
			}
			if(acha == 1)
			{
				printf("código: %s \n",rs_linhas[2]);
				printf("nome: %s \n",rs_linhas[1]);
//				printf("cpf: %s \n",rs_linhas[3]);
				printf("cpf: ");
				formatar("000.000.000-00",rs_linhas[3]);
				printf("vacina: %s \n",rs_linhas[4]);
				printf("data: %s \n",rs_linhas[5]);
				printf("lote: %s \n",rs_linhas[6]);
			}
			else
			{
				printf("Este CPF não existe no registro.\n");
			}
			mysql_free_result(consulta);
		//	cpfbusca=0;//apenas para quando digitar qualquer letra não retorna o resultado anterior,retirar não causa problema.
			system("PAUSE");
			system("cls");
			printf("Deseja continuar com a pesquisa? s/n \n");
			scanf(" %c",&busca);
			fflush(stdin);
			system("cls");
		}		
}
void excluir(MYSQL *conexao){
	char paciente[15],query[1024];
	int cod;
	printf("Digite o cpf ou codigo do paciente que deseja deletar: \n");
//	scanf("%d",&cod); apenas com num inteiro.
	scanf("%s",&paciente);
	fflush(stdin);
	
//	sprintf(query,"DELETE FROM vacinado WHERE codigo=%d",cod); Seleciona pelo codigo passa inteiro como arg.
	sprintf(query,"DELETE FROM vacinado WHERE vacinado.codigo=%s OR vacinado.cpf=%s",paciente,paciente);// Seleciona por codigo ou cpf, passa os 2 arg como strig.
//	sprintf(query,"DELETE FROM vacinado WHERE codigo=%s OR cpf=%s",paciente,paciente);//Sem passa o vacinado.cpf, tambem funciona.
	if(mysql_query(conexao,query))
	{
		printf("Tipo de Erro: %s\n",mysql_error(conexao));
		printf("não exite nenhum registro!");
		system("PAUSE");
		system("cls");
	}
	else
	{
		printf("deletado");
	}
}

int sair(){
//	char resp ='n';
	printf("Precione a tecla ENTER para sair.");
	return (0);
}
int tamanho(char string[]){
	int i = 0;
	while(string[i] != '\0'){
		i=i+1;
	}
	return i;
}
void formatar(char modelo[],char change[]){
	int i=0;
	int k=0;
	int o=0;
	char form[20]="";
	while(modelo[i] != '\0')
	{
		if(modelo[i]!='.'&&modelo[i]!='-'&&modelo[i]!='/')
		{
			form[k]=change[o];
			k=k+1;
			o=o+1;	
		}else{
			form[k]=modelo[i];
			k=k+1;
		}
		i=i+1;
	}
	printf("%s\n",form);
}
