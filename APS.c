//Salvem essa porra em arquivo C não CPP Agente está estudando programação estrutura em "C" Não Programação orientada a objeto em "Cpp"
//Fica o aviso  ↑
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
		funcionarios = (novoFuncionario*)malloc (qtdFuncionario* sizeof(novoFuncionario));
		printf("[1] Adicionar Funcionario              \n");
		printf("[2] Alterar dados de um funcionario    \n");
		printf("[3] Consultar dados de um funcionario  \n");
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
				funcionarios = (novoFuncionario*) realloc  ( funcionarios, qtdFuncionario * sizeof(novoFuncionario));		
			break;
			case 2://Alterar dados do funcionario
				printf("Insira o CPF do funcionario que você deseja alterar as informações: ");
				scanf("%d",&escolha);
				for(i = 0; i < qtdFuncionario; i++){
					// if(funcionarios == NULL){
					// 	printf("Você precisa adicionar um funcionario primeiro");
					// 	break;
					// }
					if(escolha == *funcionarios[i].cpf){//Checar se o CPF é igual para alterar os dados do dono do CPF
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
						switch (escolha){//Switch para alterar os dados do funcionario
						case 1://Nome
							// printf("Nome salvo: %s",funcionarios[i].nome);
							printf("Nome: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].nome);
							fflush(stdin);
							break;
						case 2://Idade
							// printf("Idade salva: %d",funcionarios[i].idade);
							printf("Idade: ");
							scanf("%d",&funcionarios[i].idade);
							break;
						case 3://Cargo
							// printf("Cargo salvo: %s",funcionarios[i].cargo);
							printf("Cargo: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].cargo);
							fflush(stdin);
							break;
						case 4://Cidade
							// printf("Cidade salva: %s",funcionarios[i].cidade);
							printf("Cidade: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].cidade);
							fflush(stdin);
							break;
						case 5://Endereço
							// printf("Endereço salvo: %s",funcionarios[i].endereco);
							printf("Endereço: ");
							fflush(stdin);
							scanf("%s",&funcionarios[i].endereco);
							fflush(stdin);
							break;
						case 6://Salario
							// printf("Salario salvo: %lf",funcionarios[i].salario);
							printf("Salario: ");
							scanf("%d",&funcionarios[i].salario);
							break;
						case 7://Tudo menos o CPF
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
							break;
						default:
							printf("Escolha invalida.");
							break;
						}
					}
				}
				break;
			case 3:
				printf("[1] Funcionario especifico\n");
				printf("[2] Todos os funcionario\n");
				printf("-----------------------------------------\n");
				printf("Escolha: ");
				scanf("%d",&escolha);
				switch (escolha){
				case 1:
					printf("Insira o CPF do funcionario.");
					scanf("%d",&escolha);
					for ( i = 0; i < qtdFuncionario; i++)
					{
						if(escolha == *funcionarios[i].cpf);
						
					}
					break;
				}

		}
	}
