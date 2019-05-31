//Salvem essa porra em arquivo C não CPP Agente está estudando programação estrutura em "C" Não Programação orientada a objeto em "Cpp"
//Fica o aviso  ↑
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
	//Struct para criar um funcionario
	typedef struct novoFuncionario{
			char nome[100];
			int idade;
			char cpf[12];
			char cargo[25];
			char cidade[20];
			char endereco[100];
			double salario;
		}novoFuncionario;
		
	void imprimir (int i, novoFuncionario *funcionarios);
	int check(novoFuncionario *funcionarios, int totalFuncionario, char escolha[12]);
	
	//Inicio
	int main (){
		setlocale(LC_ALL,"portuguese");
		int i, qtdFuncionario=1, busca, retorno = 0, a;
		char resp, escolha[12];
		novoFuncionario *funcionarios = NULL;//Tentativa de iniciar o codigo Null
		funcionarios = (novoFuncionario*) malloc (qtdFuncionario* sizeof(novoFuncionario));//Alocação de memoria dinamica "malloc" para iniciar um array
			do{
				printf("\n---------FORMULARIO DE CADASTRO----------\n\n");
				printf("-----------------------------------------\n\n");
				printf("[1] Adicionar Funcionario\n");
				printf("[2] Alterar dados de um funcionario\n");
				printf("[3] Consultar dados de um funcionario\n");
				printf("[4] Excluir dados de um funcionario\n");
				printf("[5] Listagem de funcionarios\n");
				printf("[6] Sair\n");
				printf("\n-----------------------------------------\n");
				printf("Escolha: ");
				scanf("%d", &busca);
				system("cls");
//					if((qtdFuncionario == 4) && (busca == 1)){
//						printf("------------------------------------");
//						printf("\nO código só armazena 10 pessoas\n");
//						printf("-----------------------------------\n");
//						break;
//					}
				switch (busca){//Switch de dados
					case 1://Adicionar um novo funcionario
						a=0;
						printf("Digite o nome completo do funcionario: ");
						fflush(stdin);
						gets(funcionarios[qtdFuncionario-1].nome);
						printf("Insira a idade desse funcionario: ");
						scanf("%d",&funcionarios[qtdFuncionario - 1].idade);
						while(a==0){
							printf("Digite o CPF do funcionario (Tenha certeza de digitalo corretamente porq não poderá muda-lo): ");
							fflush(stdin);
							gets(escolha);
							//gets(funcionarios[qtdFuncionario - 1].cpf);
							a = check(funcionarios,qtdFuncionario, escolha);
							if(a==0){
								printf("\n\nCPF JÁ CADASTRADO\n\n");								
							}
						}
						printf("Insira o cargo do funcionario: ");
						fflush(stdin);
						gets(funcionarios[qtdFuncionario - 1].cargo);
						printf("Informe a cidade do funcionario: ");
						fflush(stdin);
						gets(funcionarios[qtdFuncionario - 1].cidade);
						printf("Escreva o endereço do funcionario: ");
						fflush(stdin);
						gets(funcionarios[qtdFuncionario - 1].endereco);
						fflush(stdin);
						printf("Informe o quanto esse funcionario recebe: ");
						scanf("%lf", &funcionarios[qtdFuncionario - 1].salario);					
						qtdFuncionario++;
						//Realocação do tamanho do array por meio do "realloc"
						funcionarios = (novoFuncionario*) realloc (funcionarios, qtdFuncionario * sizeof(novoFuncionario));					
						break;
						system("cls");
					case 2://Alterar dados do funcionario
						printf("Insira o CPF do funcionario que você deseja alterar as informações: ");
						fflush(stdin);
						gets(escolha);
						for(i = 0; i < qtdFuncionario; i++){
							retorno = strncmp(escolha, funcionarios[i].cpf, 12);//Checar se o CPF é igual para alterar os dados do dono do CPF
							if(retorno == 0){
								imprimir(i, funcionarios);
								printf("-----------------------------------------\n"); 
								printf("Qual informação você deseja alterar: \n");
								printf("[1] Nome\n");
								printf("[2] Idade\n");
								printf("[3] Cargo\n");
								printf("[4] Cidade\n");
								printf("[5] Endereço\n");
								printf("[6] Salaraio\n");
								printf("[7] Tudo\n");
								printf("[8] Sair\n");
								printf("-----------------------------------------\n");
								printf("Escolha: ");
								scanf("%d",&busca);
								system("cls");
								switch (busca){//Switch para alterar os dados do funcionario
									case 1://Nome
										printf("Nome salvo: %s\n",funcionarios[i].nome);
										printf("Nome completo: ");
										fflush(stdin);
										gets(funcionarios[i].nome);
										break;
									case 2://Idade
										printf("Idade salva: %d\n",funcionarios[i].idade);
										printf("Idade: ");
										scanf("%d", &funcionarios[i].idade);
										break;
									case 3://Cargo
										printf("Cargo salvo: %s\n",funcionarios[i].cargo);
										printf("Cargo: ");
										fflush(stdin);
										gets(funcionarios[i].cargo);
										break;
									case 4://Cidade
										printf("Cidade salva: %s\n",funcionarios[i].cidade);
										printf("Cidade: ");
										fflush(stdin);
										gets(funcionarios[i].cidade);
										break;
									case 5://Endereço
										printf("Endereço salvo: %s\n",funcionarios[i].endereco);
										printf("Endereço: ");
										fflush(stdin);
										gets(funcionarios[i].endereco);
										break;
									case 6://Salario
										printf("Salario salvo: %.2lf\n",funcionarios[i].salario);
										printf("Salario: ");
										scanf("%d",&funcionarios[i].salario);
										break;
										
									case 7://Tudo menos o CPF
										printf("Digite o nome do funcionario: ");
										fflush(stdin);
										gets(funcionarios[i].nome);
										printf("Insira a idade desse funcionario: ");
										scanf("%d",&funcionarios[i].idade);
										// printf("Digite o CPF do funcionario: ");
										// scanf("%d", &funcionarios[i].cpf);
										printf("Isira o cargo do funcionario: ");
										fflush(stdin);
										gets(funcionarios[i].cargo);
										printf("Informe a cidade do funcionario: ");
										fflush(stdin);
										gets(funcionarios[i].cidade);
										printf("Escreva o endereço do funcionario: ");
										fflush(stdin);
										gets(funcionarios[i].endereco);
										fflush(stdin);
										printf("Informe o quanto esse funcionario recebe: ");
										scanf("%lf", &funcionarios[i].salario);
										break;
										imprimir(i, funcionarios);
								}     
							}
	//						else
	//							printf("CPF não encontrado. ");
						}
						system("cls");
						break;
					case 3://Consultar dados de um funcionario
						printf("Insira o CPF do funcionario: ");
						scanf("%s",&escolha);
						retorno = strncmp(escolha, funcionarios[i].cpf, 12);
						for( i = 0; i < qtdFuncionario; i++){
							retorno = strncmp(escolha, funcionarios[i].cpf, 12);
							if(retorno == 0){
								imprimir(i, funcionarios);
							}
						}
						break;
					case 4://Excluir dados de um funcionario
						printf("Insira o CPF do funcionario: ");
						scanf("%s",&escolha);
						qtdFuncionario--;
						for( i = 0; i < qtdFuncionario; i++){						
							retorno = strncmp(escolha, funcionarios[i].cpf, 12);
							if(retorno == 0){
								*funcionarios[i].nome=0;
								funcionarios[i].idade=0;
								*funcionarios[i].cpf= 0;
								*funcionarios[i].cargo=0;
								*funcionarios[i].cidade=0;
								*funcionarios[i].endereco=0;
								funcionarios[i].salario=0;
								break;
							}
						}
						printf("Os dados do funcionario foram apagados. ");
						break;
					case 5://Todos os funcionarios
						for(i = 0; i < qtdFuncionario; i++){
							if(funcionarios[i].idade != 0){
								imprimir(i, funcionarios);
							}
						}
						break;
				}
			printf("\n---------------------------------------------\n");
			printf("Deseja retornar ao menu principal? [s|n]: ");
			fflush(stdin);
			scanf("%c",&resp);
			fflush(stdin);
			system("cls");
			//}while((resp == 's') && (qtdFuncionario != 11));
		}while(resp == 's');
	}

	void imprimir (int i, novoFuncionario *funcionarios){
		printf("---------Funcionario---------\n");
		printf("Nome: %s\n",funcionarios[i].nome);
		printf("Idade: %d\n",funcionarios[i].idade);
		printf("CPF: %s\n",funcionarios[i].cpf);
		printf("Cargo: %s\n",funcionarios[i].cargo);
		printf("Cidade: %s\n",funcionarios[i].cidade);
		printf("Endereço: %s\n",funcionarios[i].endereco);
		printf("Salario: %.2lf\n",funcionarios[i].salario);
	}
	
	int check(novoFuncionario *funcionarios, int totalFuncionario, char escolha[12]){
		int i, retorna, numeroFuncionario;
		numeroFuncionario = totalFuncionario-1;
		for(i = 0; i<totalFuncionario; i++){
			retorna =strcmp(funcionarios[i].cpf,escolha);
			if(retorna==0)
				return retorna;
			else{
				
				strncpy(funcionarios[numeroFuncionario].cpf, escolha, 12);
				return retorna;	
			}
		}
	}
