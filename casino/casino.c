#include <stdio.h>
#include <locale.h>
#include <windows.h>
void quaseganho(int slot1,int slot2,int premio,int *creditos){
	if(slot1==slot2){
		printf(" Quase! Continua a tentar +%d creditos\n",(20*premio)/100);
		*creditos=*creditos+(20*premio)/100;
	}
}
int simbolos(int num,char *slot){		
				if(num>=1&&num<=30){
					*slot='L';
					return 5;
					}	
				if(num>30&&num<=55){
					*slot='C';
					return 10;
					}
				if(num>55&&num<=73){
					*slot='B';
					return 15;
					}
				if(num>73&&num<=85){
						*slot='S';
						return 30;
						}
				if(num>85&&num<=93){
						*slot='E';
						return 50;
						}
				if(num>93&&num<=98){
						*slot='D';
						return 100;
						}
				if(num>98&&num<=100){
						*slot='7';
						return 300;
						}
}
int main()
{
setlocale(LC_ALL,"Portuguese");
	int opmenu,creditos=100,jogos=0,aposta,num1,num2,num3,opslot,premio1,premio2,premio3;
	char modorapido,slot1,slot2,slot3;
	srand(time(NULL));
	do{
		printf("=== MENU ===\n");
		printf("1 - slot machine\n");
		printf("2 - Black jack\n");
		printf("3 - Ver creditos\n");
		printf("4 - Tutorial\n");
		printf("5 - Sair\n");
		printf("Escolha:");
		scanf("%d",&opmenu);
		switch (opmenu){
			case 1:
					do{
						do{
							system("cls");
							printf("=== SLOT MACHINE ===\n\n");
							printf("Creditos: %d\n",creditos);
							printf("Quanto quer apostar(0 pra sair): ");
							scanf("%d",&aposta);
							if(aposta>creditos){
								printf("\nAposta invalida, creditos insuficientes\n");
								getch();
							}
						}while(aposta>creditos);
						printf("Quer jogar no modo rapido?(s/n):");
						scanf(" %c",&modorapido);
						do{
							if(aposta>creditos){
								
							}
							num1=rand()%100+1;
							num2=rand()%100+1;
							num3=rand()%100+1;
							system("cls");
							printf("=== SLOT MACHINE ===\n\n");
							printf("Creditos: %d\n",creditos);
							printf("Aposta atual: %d\n",aposta);
							if(modorapido=='s'){
								printf("Rodando...\n");
							}
							else{
								printf("Rodando");
								Sleep(1000);
								printf(".");
								Sleep(1000);
								printf(".");
								Sleep(1000);
								printf(".\n");
								Sleep(2000);
								}
							premio1=simbolos(num1,&slot1);
							premio2=simbolos(num2,&slot2);
							premio3=simbolos(num3,&slot3);
							printf("%c |%c | %c\n",slot1,slot2,slot3);
							printf("Resultado: ");
							if(slot1==slot2 && slot2==slot3){
								creditos=creditos+(aposta*premio1);
								printf(" Ganhaste!! +%d creditos\n",aposta*premio1);
							}
							else{							
								quaseganho(slot1,slot2,premio1,&creditos);
								quaseganho(slot2,slot3,premio2,&creditos);
								if(slot1!=slot2 && slot2!=slot3 && slot1!=slot3){
									creditos=creditos-aposta;
									printf(" Perdeste!! -%d Creditos\n",aposta);
								}
								if(slot1==slot3){
									printf(" Perdeste!! -%d Creditos\n",aposta);
								}
							}
							do{
								printf("1 - Jogar outra vez com a mesma aposta\n");
								printf("2 - Mudar valor da aposta/mudar velocidade\n");
								printf("3 - Voltar ao menu\n");
								printf("Escolhe uma opção:");
								scanf("%d",&opslot);
								if(opslot==3){
									aposta=0;
									}
								if(aposta>creditos){
									printf("\nAposta invalida, creditos insuficientes\n");
									getch();
									}
								}while(aposta>creditos);
						}while(opslot!=3);
					}while(aposta!=0);
					system("cls");
					;break;
			case 3: printf("Voce tem %d creditos\n",creditos);break;
			case 4:	system("cls");
					printf("\n=== COMO JOGAR AO SLOT ===\n");
					printf("\nObjetivo:\n");
					printf("Ganhar créditos fazendo 3 símbolos iguais numa jogada.\n");
					printf("\nSímbolos e creditos:\n");
					printf("L = Limão    - 5 créditos  (30%% de chance)\n");
					printf("C = Cereja   - 10 créditos (25%% de chance)\n");
					printf("B = Banana   - 15 créditos (18%% de chance)\n");
					printf("S = Sino     - 30 créditos (12%% de chance)\n");
					printf("E = Estrela  - 50 créditos (8%% de chance)\n");
					printf("D = Diamante - 100 créditos (5%% de chance)\n");
					printf("7 = Sete     - 300 créditos (2%% de chance)\n\n");
					printf("\nComo jogar:\n");
					printf("1. Escolhe Jogar no menu.\n");
					printf("2. Escolhe quanto queres apostar nessa jogada.\n");
					printf("3. Escolhe se queres jogar no **modo rápido**:\n");
					printf(" - 's' - os rolós giram rapidamente, sem animação\n");
					printf(" - 'n' - os rolós giram lentamente, com pontos e pausas\n");
					printf("4. O programa mostra 3 símbolos aleatórios.\n");
					printf("5. Se forem 3 iguais, ganhas pontos multiplicados pela tua aposta.\n");
					printf("6. Se forem diferentes, perdes a aposta.\n");					
					printf("\nResultado da jogada:\n");
					printf("- Ganho completo: 3 símbolos iguais -> ganhas prémio multiplicado pela aposta.\n");
					printf("- Quase ganho: 2 símbolos iguais lado a lado -> recebes 20%% do prémio do símbolo.\n");
					printf("  Exemplos:\n");
					printf("   L | L | C -> quase ganho (1º e 2º lado a lado)\n");
					printf("   C | L | L -> quase ganho (2º e 3º lado a lado)\n");
					printf("   L | C | L -> não há quase ganho (não lado a lado)\n");
					printf("- Perda: nenhum símbolo repetido lado a lado -> perdes a aposta.\n\n");
					printf("\nDicas:\n");
					printf("- Quanto mais apostares, maior pode ser o prémio.\n");
					printf("- Símbolos valiosos como D ou 7 dão ainda mais pontos.\n");
					printf("- Continua a jogar enquanto tiveres créditos.\n");
					printf("- Podes ver os créditos no menu a qualquer momento.\n");
					printf("- O **modo rápido** permite rodar sem esperar pelas animações.\n");
					printf("\nPrima qualquer tecla pra voltar ao menu:");
					getch();
					system("cls");
					break;
		}
	}while(opmenu!=4);
getch();
}
