#include <stdio.h>
#include <stdlib.h>

struct inclusionFuncionario{
	char nome[50];
	int cpf[11];
	char endereco[40];
	char cidade[20];
	double salario;
	int idade;
	char cargo[25];
};

int main (){
	int escolha, qtdFuncionario=1;
	struct inclusionFuncionario *funcionarios;
	
	funcionarios = (inclusionFuncionario *) malloc (qtdFuncionario*sizeof(inclusionFuncionario));
	
	printf("Adicionar  [1]\n");
	printf("Alteração  [2]\n");
	printf("Consulta   [3]\n");
	printf("Exclusão   [4]\n");
	printf("Listagem   [5]\n");
	scanf("%d", &escolha);
	
	switch (escolha){
		case 1: 
			
			printf("Digite o nome do funcionario");
			scanf("%s", &funcionarios[(qtdFuncionario-1)].nome);
			
			
			
		qtdFuncionario++;	
		funcionarios = (inclusionFuncionario *)realloc( funcionarios, qtdFuncionario * sizeof(inclusionFuncionario));		
		break;
		
	}
	
}
