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
const char* cartas(int num) {
    switch (num) {
        case 1:  return "A";
        case 2:  return "2";
        case 3:  return "3";
        case 4:  return "4";
        case 5:  return "5";
        case 6:  return "6";
        case 7:  return "7";
        case 8:  return "8";
        case 9:  return "9";
        case 10: return "10";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
    }
}

int main()
{
setlocale(LC_ALL,"Portuguese");
	int opmenu,creditos=100,jogos=0,aposta,lose,num1,num2,num3,opslot,premio1,premio2,premio3,i,numjogador=0,maojogador,maomesa=0,nummesa,pedircarta,numjogador1,numjogador2,nummesa2,nummesa1;
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
			case 2: do{
						do{
							system("cls");
							printf("=== BLACKJACK ===\n\n");
							printf("Creditos: %d\n",creditos);
							printf("Quanto quer apostar(0 pra sair): ");
							scanf("%d",&aposta);
							if(aposta>creditos){
								printf("\nAposta invalida, creditos insuficientes\n");
								getch();
						}
						}while(aposta>creditos);
						do{
							lose=0;
							maojogador=0;
							maomesa=0;
							numjogador1=rand()%13+1;
							numjogador2=rand()%13+1;						
							nummesa1=rand()%13+1;
							nummesa2=rand()%13+1;
							system("cls");
							printf("=== BLACKJACK ===\n\n");
							printf("Creditos: %d\n",creditos);
							printf("Aposta atual: %d\n",aposta);
							printf("\n\nAs tuas cartas:\n");
							printf("[ %s ] [ %s ]  \n",cartas(numjogador1),cartas(numjogador2));
							maojogador=numjogador1+numjogador2;
							printf("\nTotal: %d\n\n",maojogador);
							printf("Cartas da mesa:\n");
							printf("[ %s ] [ ? ] \n",cartas(nummesa1));
							maomesa=nummesa1;
							pedircarta=1;
							if(maojogador==21){
								printf("Black jack voce fez 21!!!");
								printf("Resultado:\n");
								printf("Ganhou a ronda +%d creditos\n"),aposta*1.5;
								creditos=creditos+aposta*1.5;
								lose=1;
							}
							while(pedircarta==1 && maojogador<=21 && lose==0){
								printf("\n\n------------\n");
								printf("\n1 - Pedir carta\n");
								printf("2 - Parar\n");
								printf("Escolha: ");
								scanf("%d",&pedircarta);
								if (pedircarta==1){
									numjogador=rand()%13+1;
									printf("[ %s ] ",cartas(numjogador));
									maojogador=maojogador+numjogador;	
									printf("\nTotal: %d\n\n",maojogador);						
								}
							}
							if(maojogador>21){
								printf("\n\nVoce estourou!!!!\n");
								printf("Resultado:\n");
								printf("Perdeu a ronda -%d creditos\n"),aposta;
								creditos=creditos-aposta;
								lose=1;
							}
							printf("[ %s ] [ %s ] \n",cartas(nummesa1),cartas(nummesa2));
							maomesa=nummesa1+nummesa2;
							printf("\nTotal: %d\n\n",maomesa);
							if(maomesa==21 && lose==0){
								printf("Black jack Mesa fez 21!!!");
								printf("Resultado:\n");
								printf("Perdeu a ronda -%d creditos\n"),aposta*1.5;
								creditos=creditos-aposta*1.5;
								lose=1;
							}
							numjogador=0;
							if(maomesa<17 && lose==0){
								for(;maomesa<21;maomesa=maomesa+numjogador){
									printf("Mesa pede carta...\n");
									numjogador=rand()%13+1;
									printf("[ %s ] ",cartas(numjogador));
									maomesa=maomesa+numjogador;
									printf("\nTotal: %d\n\n",maomesa);						
								}
							}
							if(maomesa>21 && lose==0){
								printf("\n\nMesa estourou!!!!\n");
								printf("Resultado:\n");
								printf("Ganhaste a ronda +%d creditos\n"),aposta;
								creditos=creditos+aposta;
							}
							else{
								printf("\nTotal dos seus pontos: %d\n",maojogador);
								printf("\nTotal da mesa: %d\n",maomesa);
								if(maomesa<maojogador && lose==0){
									printf("Resultado:\n");
									printf("Ganhaste a ronda +%d creditos\n"),aposta;
									creditos=creditos+aposta;
									printf("Créditos atuais: %d"),creditos;	
								}
							}
							do{
								printf("\n1 - Jogar outra vez com a mesma aposta\n");
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
	}while(opmenu!=5);
getch();
}
