#include <stdio.h>//Biblioteca de comunicação com o usuário
#include <stdlib.h>//Biblioteca de alocação de espaço em memória 
#include <locale.h>//Biblioteca de alocações de texto por região
#include <string.h>//Biblioteca reponsável por cuidar dos strings

int registro()//Função responsável por cadastrar os usuários no sistema 
{
	//Ínicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:");//Coletando informações do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strig
	
	FILE *file;//Cria o arqivo
	file = fopen(arquivo, "w");//Cria arquivoe o "w" significa escrever
	fprintf(file,cpf);//Salva o valor da variável
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informações ficaram salvas na pasta de arquivos
	fprintf(file,",");//Colocar uma vírgula entre as informações
	fclose(file);//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//Coletando informações 
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informações ficaram salvas na pasta de arquivos
	fprintf(file,nome);//Salva o valor da variavél
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informações ficaram salvas na pasta de arquivos
	fprintf(file, ",");//Colocar uma vírgula entre as informções
	fclose(file);//Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//Coletando informações 
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informações ficaram salvas na pasta de arquivos
	fprintf(file,sobrenome);//Salva o valor da variável
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informações ficaram salvas na pasta de arquivos
	fprintf(file, ",");//Colocar uma vírgula entre as informações
	fclose(file);//Fecha o arquivo
	
	printf("Digite o cargo aser cadastrado:");//Coletando informações
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//Cria arquivo e o "a" significa que as informações ficaram salvas na pasta de arquivos
	fprintf(file,cargo);//Salva o valor da variável
	fclose(file);//Fecha o arquivo
	
    system("pause");//Da um tempo para o cliente ler a mensagem
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a liguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//Coletando informações
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;//Cria o arquivo
	file = fopen(cpf, "r");//Cria arquivo e o "r" significa ler
	
	if(file == NULL)//Caso o arquivo que procura não exista 
	{
		printf("Não foi possivel abrir arquivo, não localizado!.\n");//Mensagem que aparecerá caso o arquivo que foi solicitado não exista
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Caso o arquivo exista
	{
		printf("\nEssas são as informações do usuário:");//Mostra as informações do usuário
		printf("%s",conteudo);//%s refere-se a string
		printf("\n\n");//Pular linha
	}
	
	system("pause");//Da um tempo para o cliente ler a mensagem
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");//Pedindo para colocar as informações do usuário que deseja deletar
	scanf("%s",cpf);//%s refere-se a string
	
	
	remove(cpf);//Responsável por deletar o arquivo
	
	FILE *file;//Cria o arquivo
	file = fopen(cpf, "r");//Cria o arquivo e o "r" significa ler
	
	if(file == NULL)//Caso o arquivo não exista
	{
		printf("O usuário não existe!.\n");//Mensagem que aparecerá caso o usuário não exista
		system("pause");//Da um tempo para o cliente ler a mensagem
	}
	
	
}

int main()
{
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n");//Ínicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t-1 Registrar nomes\n");
		printf("\t-2 Consultar nomes\n");
		printf("\t-3 Deletar nomes\n\n");
		
		printf("Opção:");//Fim do menu
		
		scanf("%dS",&opcao);//Armazenando a escolha do usuário
		
		system("cls");//Responsável por limpar a tela
		
		
		switch(opcao)
		{
			case 1:
			registro();//Chamada de funções para registro
			break;	
			
			case 2:
			consulta();//Chamada de funções para consulta
			break;
			
			case 3:
			deletar();//Chamada de funções para deletar
			break;	
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa opção não está disponivel!\n");//Chamada de funções para informar o erro
			system("pause");//Da um tempo para o cliente ler a mensagem
			break;
				
		}//Fim da seleção 
	
	}
	
	
}
