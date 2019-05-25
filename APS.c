#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
	//Struct para criar um funcionario
	typedef struct novoFuncionario{
		char nome[100];
		int idade;
		int cpf[11];
		char cargo[25];
		char cidade[20];
		char endereco[100];
		double salario;
	}novoFuncionario;
	//Inicio
	int main (){
		setlocale(LC_ALL,"portuguese");
		int escolha, qtdFuncionario=1;
		novoFuncionario *funcionarios;
		//Alocação de memoria dinamica "mallc" para iniciar um array
		funcionarios = malloc (qtdFuncionario* sizeof(novoFuncionario));
		printf("Adicionar Funcionario              [1]\n");
		printf("Alterar de dados de um funcionario [2]\n");
		printf("Consulta[3]\n");
		printf("Exclusão[4]\n");
		printf("Listagem[5]\n");
		printf("-----------------------------------------");
		printf("Escolha: ");
		scanf("%d", &escolha);

		//Switch de dados
		switch (escolha){
			case 1://Adicionar um novo funcionario
				printf("Digite o nome do funcionario: ");
				fflush(stdin);
				scanf("%s", &funcionarios[(qtdFuncionario-1)].nome);
				printf("Insira a idade desse funcionario: ");
				scanf("%d",&funcionarios[qtdFuncionario - 1].idade);
				printf("Digite o CPF do funcionario: ");
				scanf("%d", &funcionarios[qtdFuncionario - 1].cpf);
				printf("Isira o cargo do funcionario: ");
				fflush(stdin);
				scanf("%s",&funcionarios[qtdFuncionario - 1].cargo);
				printf("Informe a cidade do funcionario: ");
				fflush(stdin);
				scanf("%s", &funcionarios[qtdFuncionario - 1].cidade);
				printf("Escreva o endereço do funcionario: ");
				fflush(stdin);
				scanf("%s", &funcionarios[qtdFuncionario - 1].endereco);
				printf("Informe o quanto esse funcionario recebe: ");
				scanf("%lf", &funcionarios[qtdFuncionario - 1].salario);
				qtdFuncionario++;
				//Realocação do tamanho do array por meio do "realloc"
				funcionarios =  realloc  ( funcionarios, qtdFuncionario * sizeof(novoFuncionario));		
			break;
			
				
		}
	}