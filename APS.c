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

	

	//Inicio
	int main (){
		setlocale(LC_ALL,"portuguese");
		int i, qtdFuncionario=1, busca, retorno = 0;
		char resp, escolha[12];
		novoFuncionario *funcionarios = NULL;//Tentativa de iniciar o codigo Null
		funcionarios = (novoFuncionario*) malloc (qtdFuncionario* sizeof(novoFuncionario));//Alocação de memoria dinamica "malloc" para iniciar um array
			do{
				do{
					printf("[1] Adicionar Funcionario\n");
					printf("[2] Alterar dados de um funcionario\n");
					printf("[3] Consultar dados de um funcionario\n");
					printf("[4] Excluir dados de um funcionario\n");
					printf("[5] Listagem\n");
					printf("-----------------------------------------\n");
					printf("Escolha: ");
					scanf("%d", &busca);
					system("cls");
					if((qtdFuncionario == 4) && (busca == 1)){
						printf("------------------------------------");
						printf("\nO código só armazena 10 pessoas\n");
						printf("-----------------------------------\n");
						break;
					}
					switch (busca){//Switch de dados
						case 1://Adicionar um novo funcionario
							printf("Digite o nome completo do funcionario: ");
							fflush(stdin);
							gets(funcionarios[qtdFuncionario-1].nome);
							printf("Insira a idade desse funcionario: ");
							scanf("%d",&funcionarios[qtdFuncionario - 1].idade);
							printf("Digite o CPF do funcionario (Tenha certeza de digitalo corretamente porq não poderá muda-lo): ");
							fflush(stdin);
							gets(funcionarios[qtdFuncionario - 1].cpf);
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
						case 2://Alterar dados do funcionario
							printf("Insira o CPF do funcionario que você deseja alterar as informações: ");
							fflush(stdin);
							gets(escolha);
							for(i = 0; i < qtdFuncionario; i++){
								retorno = strncmp(escolha, funcionarios[i].cpf, 12);
								if(retorno == 0){
							//	if(escolha == funcionarios[i].cpf){//Checar se o CPF é igual para alterar os dados do dono do CPF
									printf("Qual informação você deseja alterar: \n");
									printf("[1] Nome\n");
									printf("[2] Idade\n");
									printf("[3] Cargo\n");
									printf("[4] Cidade\n");
									printf("[5] Endereço\n");
									printf("[6] Salaraio\n");
									printf("[7] Tudo\n");
									printf("-----------------------------------------\n");
									printf("Escolha: ");
									scanf("%d",&busca);
									system("cls");
									switch (busca){//Switch para alterar os dados do funcionario
										case 1://Nome
											// printf("Nome salvo: %s",funcionarios[i].nome);
											printf("Nome completo: ");
											fflush(stdin);
											gets(funcionarios[i].nome);
											break;
										case 2://Idade
											// printf("Idade salva: %d",funcionarios[i].idade);
											printf("Idade: ");
											scanf("%d", &funcionarios[i].idade);
											break;
										case 3://Cargo
											// printf("Cargo salvo: %s",funcionarios[i].cargo);
											printf("Cargo: ");
											fflush(stdin);
											gets(funcionarios[i].cargo);
											break;
										case 4://Cidade
											// printf("Cidade salva: %s",funcionarios[i].cidade);
											printf("Cidade: ");
											fflush(stdin);
											gets(funcionarios[i].cidade);
											break;
										case 5://Endereço
											// printf("Endereço salvo: %s",funcionarios[i].endereco);
											printf("Endereço: ");
											fflush(stdin);
											gets(funcionarios[i].endereco);
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
										default:
											printf("Escolha invalida.");
											break;
									}
								}
		//						else
		//							printf("CPF não encontrado. ");
							}
							break;
						case 3://Consultar dados de um funcionario
							printf("Insira o CPF do funcionario: ");
							scanf("%s",&escolha);
							retorno = strncmp(escolha, funcionarios[i].cpf, 12);
							for( i = 0; i < qtdFuncionario; i++){
								retorno = strncmp(escolha, funcionarios[i].cpf, 12);
								if(retorno == 0){
									printf("---------Funcionario---------\n");
									printf("Nome: %s\n",funcionarios[i].nome);
									printf("Idade: %d\n",funcionarios[i].idade);
									printf("CPF: %s\n",funcionarios[i].cpf);
									printf("Cargo: %s\n",funcionarios[i].cargo);
									printf("Cidade: %s\n",funcionarios[i].cidade);
									printf("Endereço: %s\n",funcionarios[i].endereco);
									printf("Salario: %.2lf\n",funcionarios[i].salario);
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
							break;
						case 5://Todos os funcionarios
							for(i = 0; i < qtdFuncionario; i++){
								if(funcionarios[i].idade != 0){
									printf("---------Funcionario---------\n");
									printf("Nome: %s\n",funcionarios[i].nome);
									printf("Idade: %d\n",funcionarios[i].idade);
									printf("CPF: %s\n",funcionarios[i].cpf);
									printf("Cargo: %s\n",funcionarios[i].cargo);
									printf("Cidade: %s\n",funcionarios[i].cidade);
									printf("Endereço: %s\n",funcionarios[i].endereco);
									printf("Salario: %.2lf\n",funcionarios[i].salario);
								}
							}
							break;
					}
				printf("Deseja retornar ao menu principal? [s|n] \n ");
				fflush(stdin);
				scanf("%c",&resp);
				fflush(stdin);	
			}while((resp == 's') && (qtdFuncionario != 11));
		}while(resp == 's');
	}

//	int	compara (char escolha, int qtdFuncionario, novoFuncionario *funcionario){
//		int i, retorno;
//		for(i = 0; i < qtdFuncionario; i++){
//			retorno = strncmp(escolha, *funcionario[i]->cpf, 12);
//			if(retorno == 0){
//				return 0;
//			}
//			else
//				return -1;
//		}
//	}
	
	
