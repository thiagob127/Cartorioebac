#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro(){
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	strcpy(arquivo,cpf); //copiar os valores da string
	
	FILE*file; //cria o  arquivo
	file=fopen(arquivo,"w");
	fprintf(file,"\nCPF: %s",cpf); //salva o vqlor da variável
	fclose(file); //fecha o arquivo

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,"\nnome: %s ",nome); //uma forma de salvar no arquivo, para quando ser colsultado não ficar com a informação jogada
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,"\ncargo: %s",cargo);
	fclose(file);
	system("pause");//muito importante para não dar erro
}

int consulta(){
	char cpf[40];
	char con[200];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o cpf a ser consutado: ");
	scanf("%s",cpf);
	
	FILE*file; //abre e lê o arquivo cpf
	file=fopen(cpf,"r");
	
	if(file==NULL){
		printf("CPF não localizado!");
	}
	
	while(fgets(con,200,file)!=NULL){ //mostra o que tem no arquivo
	
		printf("%s\n",con);
		
	}
	fclose(file);
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	
	scanf("%s",cpf);
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL){//validação do cpf se está ou não no sistema
		printf("O usuário não se encontra no sistema");
		system("pause");
	}
	else{
		fclose(file);
		remove(cpf);
		printf("Cadastro deletado!");
		system("pause");
	}
}

int main(){

	int opcao=0; //definindo variáveis
	int a=1;
	
	for(a=1;a=1;){
	
		system("cls");
		
		setlocale(LC_ALL,"Portuguese");

		printf("Registro de alunos EBAC\n\n"); //Menu
		printf("Escolha entre as opções 1 a 3 no menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n\n"); //Fim do menu
		
		printf("Opção:");
		scanf("%d",&opcao);
	
		system("cls"); //limpar a tela
	
		switch(opcao){
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Opção inválida");
			system("pause");
			break;
		
		}
	}
}
