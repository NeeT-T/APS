//Salvem essa porra em arquivo C não CPP Agente está estudando programação estrutura em "C" Não Programação orientada a objeto em "Cpp"
//Fica o aviso  ↑
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
	//Struct para criar um funcionario
	typedef struct novoFuncionario{
			char nome[60];
			int idade;
			char cpf[12];
			char cargo[25];
			char cidade[20];
			char endereco[100];
			double salario;
		}novoFuncionario;
		
	int qtdFuncionario = 1;
	
	void cadastroFuncionario(novoFuncionario *funcionarios);
	void excluir(novoFuncionario *funcionarios, char escolha[]);
	void imprimir (int i, novoFuncionario *funcionarios);
    int comparar(novoFuncionario *funcionarios,int i, char escolha[]);
	void altNome(int i, novoFuncionario *funcionarios);
	void altIdade(int i, novoFuncionario *funcionarios);
	void altCargo(int i, novoFuncionario *funcionarios);
	void altCidade(int i, novoFuncionario *funcionarios);
	void altEndereco(int i, novoFuncionario *funcionarios);
	void altSalario(int i, novoFuncionario *funcionarios);
	void altAPorraToda(int i, novoFuncionario *funcionarios);

	//Inicio
	int main (){
		setlocale(LC_ALL,"portuguese");
		int busca;
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
			switch (busca){//Switch de menu
				int i;
				case 1://Adicionar um novo funcionario
					cadastroFuncionario(funcionarios);
					qtdFuncionario++;
					funcionarios = (novoFuncionario*) realloc (funcionarios, qtdFuncionario * sizeof(novoFuncionario));//Realocação do tamanho do array por meio do "realloc"
					break;
					system("cls");
				case 2://Alterar dados do funcionario
					printf("Insira o CPF do funcionario que você deseja alterar as informações: ");
					fflush(stdin);
					gets(escolha);
					for(i = 0; i < qtdFuncionario; i++){
						int retorno;
						retorno = comparar(funcionarios, i, escolha);
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
									altNome(i, funcionarios);
								break;
								case 2://Idade
									altIdade(i, funcionarios);
								break;
								case 3://Cargo
									altCargo(i, funcionarios);
								break;
								case 4://Cidade
									altCidade(i, funcionarios);
								break;
								case 5://Endereço
									altEndereco(i, funcionarios);
								break;
								case 6://Salario
									altSalario(i, funcionarios);
								break;
								case 7://Tudo menos o CPF
									altAPorraToda(i, funcionarios);
								break;
							}
						}
					}
					system("cls");
					break;
				case 3://Consultar dados de um funcionario
					printf("Insira o CPF do funcionario: ");
					scanf("%s",&escolha);
					for( i = 0; i < qtdFuncionario; i++){
						int retorno;
						retorno = comparar(funcionarios, i, escolha);
						if(retorno == 0){
							imprimir(i, funcionarios);
						}
					}
					if(qtdFuncionario == 1)
						printf("Nenhum funcionario cadastrado");
					break;
				case 4://Excluir dados de um funcionario
					printf("Insira o CPF do funcionario: ");
					scanf("%s",&escolha);
					qtdFuncionario--;
					for(i = 0; i < qtdFuncionario; i++){
						int retorno;
						retorno = comparar(funcionarios,i,escolha);
						if(retorno == 0)
							imprimir(i, funcionarios);
					}
					excluir(funcionarios, escolha);
					printf("Os dados do funcionario foram apagados. ");
					break;
				case 5://Todos os funcionarios
					if(qtdFuncionario == 1){
						printf("Nenhum funcionario cadastrado");
						break;
					}
					for(i = 0; i < qtdFuncionario; i++){
						if(funcionarios[i].idade != 0){
							imprimir(i, funcionarios);
						}
					}
					if(qtdFuncionario == 1)
						printf("Nenhum funcionario cadastrado");
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
	
	void excluir(novoFuncionario *funcionarios, char escolha[]){
	int retorno, i;
		for( i = 0; i < qtdFuncionario; i++){
			retorno = comparar(funcionarios, i, escolha);
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
    }
    
    int comparar(novoFuncionario *funcionarios,int i, char escolha[]){
        return strncmp(escolha, funcionarios[i].cpf, 12);  
    }
    
    void cadastroFuncionario(novoFuncionario *funcionarios){
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
	}

	void altNome(int i, novoFuncionario *funcionarios){
		printf("Nome salvo: %s\n",funcionarios[i].nome);
		printf("Nome completo: ");
		fflush(stdin);
		gets(funcionarios[i].nome);
		printf("\nSucesso na alteração.\n");
	}

	void altIdade(int i, novoFuncionario *funcionarios){
		printf("Idade salva: %d\n",funcionarios[i].idade);
		printf("Idade: ");
		scanf("%d", &funcionarios[i].idade);
		printf("\nSucesso na alteração.\n");
	}

	void altCargo(int i, novoFuncionario *funcionarios){
		printf("Cargo salvo: %s\n",funcionarios[i].cargo);
		printf("Cargo: ");
		fflush(stdin);
		gets(funcionarios[i].cargo);
		printf("\nSucesso na alteração.\n");
	}

	void altCidade(int i, novoFuncionario *funcionarios){
		printf("Cidade salva: %s\n",funcionarios[i].cidade);
		printf("Cidade: ");
		fflush(stdin);
		gets(funcionarios[i].cidade);
		printf("\nSucesso na alteração.\n");
	}

	void altEndereco(int i, novoFuncionario *funcionarios){
		printf("Endereço salvo: %s\n",funcionarios[i].endereco);
		printf("Endereço: ");
		fflush(stdin);
		gets(funcionarios[i].endereco);
		printf("\nSucesso na alteração.\n");
	}

	void altSalario(int i, novoFuncionario *funcionarios){
		printf("Salario salvo: %.2lf\n",funcionarios[i].salario);
		printf("Salario: ");
		scanf("%d",&funcionarios[i].salario);
		printf("\nSucesso na alteração.\n");
	}

	void altAPorraToda(int i, novoFuncionario *funcionarios){
		printf("Digite o nome do funcionario: ");
		fflush(stdin);
		gets(funcionarios[i].nome);
		printf("Insira a idade desse funcionario: ");
		scanf("%d",&funcionarios[i].idade);
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
		printf("\nSucesso na alteração.\n");
	}



