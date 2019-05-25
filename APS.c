#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stddef.h>
#define NULL ((void *)0)
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
		int escolha, i, qtdFuncionario=1;
		novoFuncionario *funcionarios = NULL;

		//Alocação de memoria dinamica "malloc" para iniciar um array
		funcionarios = malloc (qtdFuncionario* sizeof(novoFuncionario));
		printf("Adicionar Funcionario              [1]\n");
		printf("Alterar dados de um funcionario    [2]\n");
		printf("Consulta[3]\n");
		printf("Exclusão[4]\n");
		printf("Listagem[5]\n");
		printf("-----------------------------------------\n");
		printf("Escolha: ");
		scanf("%d", &escolha);
		//Switch de dados
		system("cls");
		switch (escolha){
			case 1://Adicionar um novo funcionario
				printf("Digite o nome do funcionario: ");
				fflush(stdin);
				scanf("%s", &funcionarios[(qtdFuncionario-1)].nome);
				printf("Insira a idade desse funcionario: ");
				scanf("%d",&funcionarios[qtdFuncionario - 1].idade);
				printf("Digite o CPF do funcionario (Tenha certeza de digitalo corretamente porq não poderá muda-lo): ");
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
				fflush(stdin);
				printf("Informe o quanto esse funcionario recebe: ");
				scanf("%lf", &funcionarios[qtdFuncionario - 1].salario);
				qtdFuncionario++;
				//Realocação do tamanho do array por meio do "realloc"
				funcionarios =  realloc  ( funcionarios, qtdFuncionario * sizeof(novoFuncionario));		
			break;
			case 2://Alterar dados do funcionario
				printf("Insira o CPF do funcionario que você deseja alterar as informações: ");
				scanf("%d",&escolha);
				for(i = 0; i < qtdFuncionario; i++){
					// if(funcionarios == NULL){
					// 	printf("Você precisa adicionar um funcionario primeiro");
					// 	break;
					// }
					if(escolha == *funcionarios[i].cpf){
						printf("Qual informação você deseja alterar: ");
						printf("[1] Nome\n");
						printf("[2] Idade\n");
						printf("[3] Cargo\n");
						printf("[4] Cidade\n");
						printf("[5] Endereço\n");
						printf("[6] Salaraio\n");
						printf("[7] Tudo\n");
						printf("-----------------------------------------\n");
						printf("Escolha: ");
						scanf("%d",&escolha);
						system("cls");
						switch (escolha){
						case 1:
							// printf("Nome salvo: %s",funcionarios[i].nome);
							printf("Nome: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].nome);
							fflush(stdin);
							break;
						case 2:
							// printf("Idade salva: %d",funcionarios[i].idade);
							printf("Idade: ");
							scanf("%d",&funcionarios[i].idade);
							break;
						case 3:
							// printf("Cargo salvo: %s",funcionarios[i].cargo);
							printf("Cargo: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].cargo);
							fflush(stdin);
							break;
						case 4:
							// printf("Cidade salva: %s",funcionarios[i].cidade);
							printf("Cidade: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].cidade);
							fflush(stdin);
							break;
						case 5:
							// printf("Endereço salvo: %s",funcionarios[i].endereco);
							printf("Endereço: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].endereco);
							fflush(stdin);
							break;
						case 6:
							// printf("Salario salvo: %lf",funcionarios[i].salario);
							printf("Salario: ");
							scanf("%d",&funcionarios[i].salario);
							break;
						case 7:
							// printf("Nome salvo: %s",funcionarios[i].nome);
							// printf("Idade salva: %d",funcionarios[i].idade);
							// printf("Cargo salvo: %s",funcionarios[i].cargo);
							// printf("Cidade salva: %s",funcionarios[i].cidade);
							// printf("Endereço salvo: %s",funcionarios[i].endereco);
							// printf("Salario salvo: %lf",funcionarios[i].salario);

							printf("Digite o nome do funcionario: ");
							fflush(stdin);
							scanf("%s", &funcionarios[i].nome);
							printf("Insira a idade desse funcionario: ");
							scanf("%d",&funcionarios[i].idade);
							// printf("Digite o CPF do funcionario: ");
							// scanf("%d", &funcionarios[i].cpf);
							printf("Isira o cargo do funcionario: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].cargo);
							printf("Informe a cidade do funcionario: ");
							fflush(stdin);
							scanf("%s", &funcionarios[i].cidade);
							printf("Escreva o endereço do funcionario: ");
							fflush(stdin);
							scanf("%s", &funcionarios[i].endereco);
							fflush(stdin);
							printf("Informe o quanto esse funcionario recebe: ");
							scanf("%lf", &funcionarios[i].salario);
						}
					}
				}
		}
	}
