#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> // biblioteca de alocacao de espaco em memoria
#include <locale.h> //Biblioteca de alocacoes de texto po regiao
#include <string.h>//biblioteca responsavel por cuidar das string

	int registro()//funcao responsavel por cadastrar os usuarios no sistema
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//inicio criacao de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final da criacao de variaveis/string
		
		printf("Digite o CPF a ser cadastrado:");//coletando informação do usuário
		scanf("%s", cpf);//%s refere-se a string
		
		strcpy(arquivo, cpf);//responsavel por copiar os valores das string
		
		FILE *file;//cria o arquivo 
		file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
		fprintf(file,cpf);//salva o valor da variavel
		fclose(file);//fecha o arquivo
		
		file = fopen(arquivo, "a");//atualizar o arquivo o "a" siginifica atualizar 
		fprintf(file, ",");//salvar o valor da variavel
		fclose(file);//fechar o arquivo
		
		printf("Digite o nome a ser cadastrado: ");//coletando informação do usuario
		scanf("%s",nome);//%s refere-se a string
		
		file = fopen(arquivo, "a");//atualizar o arquivo o "a" significa atulizar
		fprintf(file,nome);//salvar o valor da variavel
		fclose(file);//fechar o arquvio
		
		file = fopen(arquivo, "a");//atualizar o arquivo o "a" siginifica atualizar
		fprintf(file, ",");//salvar a variavel
		fclose(file);//fechar o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do arquivo
		scanf("%s",sobrenome);//%s refere-se a string
		
		file =fopen(arquivo, "a");//atualizar o arquivo "a" significa atualizar
		fprintf(file,sobrenome);//salvar o valor da variavel
		fclose(file);//fechar o arquivo
		
		file = fopen(arquivo, "a");//atualizar o arquivo "a" significa atualizar
		fprintf(file, ",");//salvar o valor da variavel
		fclose(file);//fechar o arquivo
		
		printf("Digite o cargo a ser cadastrado: ");//coletando informção do arquivo
		scanf("%s", cargo);//%s refere-se a string
		
		file = fopen(arquivo, "a");//atualizar o arquivo "a" significa atualizar
		fprintf(file,cargo);//salvar o valor da variavel
		fclose(file);//fechar o arquivo
		
		file = fopen(arquivo, "a");//atualizar o arquivo "a" signica atualizar
		fprintf(file, ",");//salvar o valor da variavel
		fclose(file);//fechar o arquivo
		
		system("pause");//voltar para o inicio
	}
	
	int consulta()
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		//inicio da crição do variaveis/string
		char cpf[40];
		char conteudo[200];
		//fim da crição da variaveis/string
		
		printf("Digite o CPF a ser consultado: ");//coletando informção do arquivo
		scanf("%s",cpf);//%s refere-se a string
		
		FILE *file;//criar o arquivo
		file = fopen(cpf,"r");//abrir um arquivo para leitura
		
		if(file == NULL)//quando o arquivo nao  for encontrado ele fica nulo
		{
			printf("nao foi possivel localizar esse CPF!. \n ");//coletando informção do arquivo
		}
		
		while(fgets(conteudo, 200, file) != NULL)//repitir o bloco de codigo
		{
			printf("\nEssa sao as informacoes do usuario: ");//coletando informação do arquivo
			printf("%s", conteudo);//%s refere-se a string
			printf("\n\n");// para dar spaço
		}
		
		system("pause");//voltar para o inicio
	}
	
	int deletar()
	{
		//inicio criação da variavel/string
		char cpf[40];
		//fim da criação da variaveis/string
		
		printf("Digite o CPF a ser Deletado: ");//coloetando informção do arquivo
		scanf("%s", cpf);//%s refere-se a string
		
		
		
		FILE *file;//criar o  arquivo
		file = fopen(cpf, "r");//abrir um arquivo para leitura
		
		if(file == NULL)//quando o arquivo nao  for encontrado ele fica nulo
		{
			printf("O usuario nao localizado no sistema!.\n");//coletando informação do aqruivo
			system("pause");//voltar para o inicio
		}
		
		else//serve como uma alternativa para o caso de a condição inicial não se satisfeita
		{
			fclose(file);//fecha o arquivo, pq ele existe
			remove(cpf);//ele deleta o arquivo
			printf("Usuario Deletado com sucesso!.\n");//coletndo informação do arquivo
			system("pause");//voltar para o inicio
		
		}		
		
		
	}

int main()//ponto de partida para execução do programa
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); // definindo a linguagem do programa
	
		printf("### Cartorio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a opcao deseja do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("opcao: "); //fim  do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls");//responsavel por limpar a tela
		
		switch(opcao)//inicio da selecao / escolha
		{
			// inicio da selecao
			case 1:
				registro();//chamar de funcoes
				break;
				
			case 2:
				consulta();//chamar os registros
			 	break;
			 	
			case 3:
				deletar();//deletar os registros
				break;
				
				
			default:
				printf("Essa opcao nao esta disponivel!\n");
				system("pause");
				break;
				// fim da selecao
					
		}
	
	
	
		
		system("pause");//voltar para o inicio
		
}
}
