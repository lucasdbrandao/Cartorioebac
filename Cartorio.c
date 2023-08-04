#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região (no caso BRASIL)
#include <string.h> //biblioteca responsavel por cuidar das strings


int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	
	//inicio da ciracao de strings/variaveis
	char arquivo[40];	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis
	
	
	printf("digite o CPF a ser cadastrado: ");//Coletando informacao do usuario
	scanf("%s",cpf); // Armazena a resposta do usuario (%s refere-se a string!)
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file); //fecha o arquivo
			
	file = fopen(arquivo, "a");//Abre e altera o arquivo ja escrito com o "w" (write)
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coleta informacao do usuario
	scanf("%s",nome);//Armazena a resposta do usuario (%s refere-se a string!)
	
	file = fopen(arquivo, "a");//abre o arquivo para alterar
	fprintf(file,nome);//salva o valor da variavel nome
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo para alterar
	fprintf(file,",");//Adiciona uma virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coleta informacao do usuario
	scanf("%s",sobrenome);//Escaneia e armazena a resposta do usuario (%s refere-se a string)
	
	file = fopen(arquivo, "a");//abre o arquivo para alteracoes
	fprintf(file,sobrenome);//salva o valora da variavel sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo para alteracoes
	fprintf(file,",");//adiciona uma virgula
	fclose(file);//fecha o arquivo
	
	printf("Digite o Cargo a ser cadastrado: ");//Coleta informacao do usuario
	scanf("%s", cargo);//Escaneia e armazena a resposta do usuario (%s para string)
	
	file = fopen(arquivo, "a");//abre o arquivo para "a" alterar
	fprintf(file,cargo);//salva o valor da variavel cargo
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o sistema
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	
	char cpf[40]; // variavel da resposta do usuario para qual ele quer consultar
	char conteudo[200];//conteudo do arquivo
	
	printf("Digite o CPF a ser consultado: ");//Recebe o usuario a ser consultado
	scanf("%s", cpf);//Escaneia a resposta do usuario e salva o valor da variavel CPF
	
	FILE *file;
	file = fopen(cpf,"r");//abre e le tudo o que estiver dentro do arquivo CPF
	
	if(file == NULL)//Usando a condicional para comparar se o valor digitado pelo usuario existe ou nao
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado! \n");//caso nao exista, avisa o usuario
	}
	
	while(fgets(conteudo, 200, file)!= NULL)//salvando na string conteudo, os 200 caracteres que estao dentro do arquivo (para quando for NULO e sai do loop)
	{
		printf("\nEssas sao as informacoes do usuario: ");//retorna as informacoes do usuario
		printf("%s", conteudo);//salva o conteudo dentro da string
		printf("\n\n");//pula 2 linhas
		
	}
	
	system("pause");//pause o sistema
	
}


int deletar()
{
	char cpf[40];//Cria a variavel CPF com 40 caracteres
	
	printf("Insira o CPF a ser deletado: ");//Coleta informacoes do usuario
	scanf("%s",cpf);//Salva o valor inserido na string cpf
	
	remove(cpf);//DELETA a variavel CPF
	
	FILE *file;
	file = fopen(cpf,"r");//Abre o arquivo para leitura
	
	if(file==NULL)//Condicional, caso a informacao inserida pelo usuario nao exista no arquivo
	{
		printf("CPF nao encontrado\n");//retorna a informacao para o usuario
		system("pause");//pausa o sistema
		
	}
		
	if(file!=NULL)//Caso a informacao inserida pelo usuario NAO seja nula, e delete com sucesso o CPF requisitado
	{
		printf("Usuario deletado com sucesso!\n\n");//retorna a informacao para o usuario
		system("pause");//pausa o sistema
	}
	fclose(file);	//fecha o arquivo
	
	
}


int main()//codigo principal
{
	int opcao=0;//Definindo variaveis
	int laco=1;//definindo uma variavel para um laco de repeticao infinito
	char senhadigitada[]="a";
	int comparacao;
	
	printf("###Cartorio da EBAC###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");//cria uma variavel com a funcao strcmp para comparar 2 strings
	
	if(comparacao==0)//caso o valor da comparacao nao de diferenca ou seja == 0, entao prossegue com o codigo
	{
	
		system("cls");
		for(laco=1;laco=1;)//o valor de laco nunca vai mudar, portanto nunca vai sair do loop
		{

			system("cls");//Limpa a tela do programa
		
		
		
			setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		
			printf("###Olá, seja bem vindo ao Cartório da EBAC###\n\n");//inicio do menu
			printf("Escolha a opção desejada:\n\n");
			printf("\t1- Registrar nomes\n");
			printf("\t2- Consultar nomes\n");
			printf("\t3- Deletar nomes\n");
			printf("\t4- Sair do sistema\n\n");
			printf("Opcao: " ); //final do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuario
	
			system("cls");//limpa a tela do programa
		
		
			switch(opcao) //inicio da selecao/comeca o loop de switch case para verificar condicionais (no caso compara o valor da variavel "opcao" a 1 2 3 ou default.)
			{
				case 1:
				registro();//chama a funcao registro que esta fora do codigo principal
				break;//para o loop de switchcase
				
			
				case 2:
				consulta();//chama a funcao consulta que esta fora do codigo principal
				break;//para o loop de switchcase
			
				case 3:
				deletar();//chama a funcao deletar que esta fora do codigo principal
				break;//para o loop de switchcase
					
			
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0; //quebra o código para sair do sistema
			
			
				default://caso o usuario digite qualquer outro numero fora do case
				printf("Essa opção não esta disponivel\n");//retorna a info para o usuario
				system("pause");//pausa o sistema
				break;//sai do loop de switchcase
			}
		}			
	} 
	
		else
			printf("senha incorreta");
}


		
