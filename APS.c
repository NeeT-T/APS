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
		int i, qtdFuncionario=1, busca, retorno;
		char resp, escolha[11];
		//Tentativa de iniciar o codigo Null
		novoFuncionario *funcionarios = NULL;
		//Alocação de memoria dinamica "malloc" para iniciar um array
		do{	
			funcionarios = (novoFuncionario*) malloc (qtdFuncionario* sizeof(novoFuncionario));
			printf("[1] Adicionar Funcionario\n");
			printf("[2] Alterar dados de um funcionario\n");
			printf("[3] Consultar dados de um funcionario\n");
			printf("[4] Excluir dados de um funcionario\n");
			printf("[5] Listagem\n");
			printf("-----------------------------------------\n");
			printf("Escolha: ");
			scanf("%d", &busca);
			//Switch de dados
			system("cls");
			
			switch (busca){
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
					printf("--------");
					for ( i = 0; i < qtdFuncionario; i++){
						printf("---------Funcionario---------\n");
						printf("Nome: %s\n",funcionarios[i].nome);
						printf("Idade: %d\n",funcionarios[i].idade);
						printf("CPF: %s\n",funcionarios[i].cpf);
						printf("Cargo: %s\n",funcionarios[i].cargo);
						printf("Cidade: %s\n",funcionarios[i].cidade);
						printf("Endereço: %s\n",funcionarios[i].endereco);
						printf("Salario: %0.2f\n",funcionarios[i].salario);
					}
					qtdFuncionario++;
					//Realocação do tamanho do array por meio do "realloc"
					funcionarios = (novoFuncionario*) realloc (funcionarios, qtdFuncionario * sizeof(novoFuncionario));
					break;
				case 2://Alterar dados do funcionario
					printf("Insira o CPF do funcionario que você deseja alterar as informações: ");
					gets(escolha);
					for(i = 0; i < qtdFuncionario; i++){	
						retorno = strncmp(escolha, funcionarios[i].cpf, 11);
						printf("%d \n", retorno);
						if(retorno == -1){
					//	if(escolha == funcionarios[i].cpf){//Checar se o CPF é igual para alterar os dados do dono do CPF
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
							scanf("%d",&busca);
							system("cls");
							switch (busca){//Switch para alterar os dados do funcionario
								case 1://Nome
									// printf("Nome salvo: %s",funcionarios[i].nome);
									printf("Nome completo: ");
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
									gets(funcionarios[i].cargo);
									break;
								case 4://Cidade
									// printf("Cidade salva: %s",funcionarios[i].cidade);
									printf("Cidade: ");
									gets(funcionarios[i].cidade);
									break;
								case 5://Endereço
									// printf("Endereço salvo: %s",funcionarios[i].endereco);
									printf("Endereço: ");
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
					}
					break;
				case 3://Consultar dados de um funcionario
					printf("[1] Funcionario especifico\n");
					printf("[2] Todos os funcionario\n");
					printf("-----------------------------------------\n");
					printf("Escolha: ");
					scanf("%d",&busca);
					switch (busca){
						//{Deem um jeito nesse Case 1 porq ele tá bugado mesmo não estando igual ele coloca
						//Um valor aleatorio isso aconteceu nos meus testes mais ainda não fiz um completo
						//Então é um dar uma checada.}
						case 1://Funcionario especifico
							printf("Insira o CPF do funcionario: ");
							scanf("%d",&escolha);
							for ( i = 0; i < qtdFuncionario; i++){
								if(escolha == funcionarios[i].cpf){
									printf("---------Funcionario---------\n");
									printf("Nome: %s\n",funcionarios[i].nome);
									printf("Idade: %d\n",funcionarios[i].idade);
									printf("CPF: %s\n",funcionarios[i].cpf);
									printf("Cargo: %s\n",funcionarios[i].cargo);
									printf("Cidade: %s\n",funcionarios[i].cidade);
									printf("Endereço: %s\n",funcionarios[i].endereco);
									printf("Salario: %s\n",funcionarios[i].salario);
								}
							}
						case 2://Todos os funcionarios
							for(i = 0; i < qtdFuncionario; i++){
								printf("---------Funcionario---------\n");
								printf("Nome: %s\n",funcionarios[i].nome);
								printf("Idade: %d\n",funcionarios[i].idade);
								printf("CPF: %s\n",funcionarios[i].cpf);
								printf("Cargo: %s\n",funcionarios[i].cargo);
								printf("Cidade: %s\n",funcionarios[i].cidade);
								printf("Endereço: %s\n",funcionarios[i].endereco);
								printf("Salario: %s\n",funcionarios[i].salario);
							}
					}
					break;
				case 4://Excluir dados de um funcionario
					
					break;
			}
			printf("Deseja retornar ao menu principal? s/n \n ");
			fflush(stdin);
			scanf("%c",&resp);
			fflush(stdin);
		} while(resp == 's');
	}
