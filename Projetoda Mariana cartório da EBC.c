#include <stdio.h>//Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//Biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h>//Biblioteca de aloca��es de texto por regi�o
#include <string.h>//Biblioteca repons�vel por cuidar dos strings

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//�nicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:");//Coletando informa��es do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores das strig
	
	FILE *file;//Cria o arqivo
	file = fopen(arquivo, "w");//Cria arquivoe o "w" significa escrever
	fprintf(file,cpf);//Salva o valor da vari�vel
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informa��es ficaram salvas na pasta de arquivos
	fprintf(file,",");//Colocar uma v�rgula entre as informa��es
	fclose(file);//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//Coletando informa��es 
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informa��es ficaram salvas na pasta de arquivos
	fprintf(file,nome);//Salva o valor da variav�l
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informa��es ficaram salvas na pasta de arquivos
	fprintf(file, ",");//Colocar uma v�rgula entre as inform��es
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//Coletando informa��es 
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informa��es ficaram salvas na pasta de arquivos
	fprintf(file,sobrenome);//Salva o valor da vari�vel
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informa��es ficaram salvas na pasta de arquivos
	fprintf(file, ",");//Colocar uma v�rgula entre as informa��es
	fclose(file);//Fecha o arquivo
	
	printf("Digite o cargo aser cadastrado:");//Coletando informa��es
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informa��es ficaram salvas na pasta de arquivos
	fprintf(file,cargo);//Salva o valor da vari�vel
	fclose(file);//Fecha o arquivo
	
    system("pause");//Da um tempo para o cliente ler a mensagem
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a liguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//Coletando informa��es
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;//Cria o arquivo
	file = fopen(cpf, "r");//Cria arquivo e o "r" significa ler
	
	if(file == NULL)//Caso o arquivo que procura n�o exista 
	{
		printf("N�o foi possivel abrir arquivo, n�o localizado!.\n");//Mensagem que aparecer� caso o arquivo que foi solicitado n�o exista
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Caso o arquivo exista
	{
		printf("\nEssas s�o as informa��es do usu�rio:");//Mostra as informa��es do usu�rio
		printf("%s",conteudo);//%s refere-se a string
		printf("\n\n");//Pular linha
	}
	
	system("pause");//Da um tempo para o cliente ler a mensagem
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");//Pedindo para colocar as informa��es do usu�rio que deseja deletar
	scanf("%s",cpf);//%s refere-se a string
	
	
	remove(cpf);//Respons�vel por deletar o arquivo
	
	FILE *file;//Cria o arquivo
	file = fopen(cpf, "r");//Cria o arquivo e o "r" significa ler
	
	if(file == NULL)//Caso o arquivo n�o exista
	{
		printf("O usu�rio n�o existe!.\n");//Mensagem que aparecer� caso o usu�rio n�o exista
		system("pause");//Da um tempo para o cliente ler a mensagem
	}
	
	
}

int main()
{
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n");//�nicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t-1 Registrar nomes\n");
		printf("\t-2 Consultar nomes\n");
		printf("\t-3 Deletar nomes\n\n");
		
		printf("Op��o:");//Fim do menu
		
		scanf("%dS",&opcao);//Armazenando a escolha do usu�rio
		
		system("cls");//Respons�vel por limpar a tela
		
		
		switch(opcao)
		{
			case 1:
			registro();//Chamada de fun��es para registro
			break;	
			
			case 2:
			consulta();//Chamada de fun��es para consulta
			break;
			
			case 3:
			deletar();//Chamada de fun��es para deletar
			break;	
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa op��o n�o est� disponivel!\n");//Chamada de fun��es para informar o erro
			system("pause");//Da um tempo para o cliente ler a mensagem
			break;
				
		}//Fim da sele��o 
	
	}
	
	
}
