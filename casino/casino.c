#include <stdio.h>
#include <locale.h>
#include <windows.h>
void fimaposta(int aposta,int creditos,int *opslot){
	do{
		printf("\n------------------------------------------------\n");
		printf("1 - Jogar outra vez com a mesma aposta\n");
		printf("2 - Mudar valor da aposta\n");
		printf("3 - Voltar ao menu\n");
		printf("Escolhe uma opção:");
		scanf("%d",&*opslot);
		if(aposta>creditos){
			printf("\nAposta invalida, creditos insuficientes\n");
			getch();
		}
	}while(aposta>creditos);
}
void configuracoes(autosave,notificacoes){
	printf("============Configuraçoes============\n");
	printf("1- Salvar creditos automaticamente ");
	if(autosave)
		printf("ATIVO\n");
	else 
		printf("DESATIVADO\n");
	printf("2- Notificaçoes ");
	if(notificacoes)
		printf("ATIVO\n");
	else 
		printf("DESATIVADO\n");
}
void guardarcreditos(int creditos,int notificacoes,int autosave){
	int checkcreditos;
	if (autosave){
		if(notificacoes){
			printf("A salvar creditos.");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".\n\n");
		}
		FILE *f;
		f=fopen("creditos.txt","w");
		fprintf(f,"%d",creditos);
		fclose(f);
	}
}
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
	int opmenu,vermelho,azul,notificacoes=1,autosave=1,creditos=100,jogos=0,aposta,lose,num1,num2,num3,opslot,premio1,premio2,premio3,i,numjogador=0,maojogador,maomesa=0,nummesa,pedircarta,numjogador1,numjogador2,nummesa2,nummesa1;
	char modorapido,slot1,slot2,slot3,sn;
	FILE *f;
	srand(time(NULL));
	f=fopen("creditos.txt","r");
	if (f == NULL){
		creditos=100;
	}
	else{
		fscanf(f,"%d",&creditos);
		fclose(f);
	}
	f=fopen("config.txt","r");
	if (f == NULL){
		autosave=1;
		notificacoes=1;
	}
	else{
		fscanf(f,"%d",&autosave);
		fscanf(f,"%d",&notificacoes);
		fclose(f);
		printf("LOADED!\n");
	}
	configuracoes(autosave,notificacoes);
	printf("\nVoce tem %d creditos\n",creditos);
	printf("Pressa qualquer tecla pra Continuar...");
	getch();
	do{
		system("cls");
		printf("=== MENU ===\n");
		printf("1 - slot machine\n");
		printf("2 - Black jack\n");
		printf("3 - Azul VS Vermelho\n");
		printf("4 - Ver creditos\n");
		printf("5 - Tutorial\n");
		printf("6 - Reset\n");
		printf("7 - Configuraçoes\n");
		printf("8 - Sair\n");
		printf("Escolha:");
		scanf("%d",&opmenu);
		switch (opmenu){
			case 1:
					do{
						do{
							system("cls");
							printf("=== SLOT MACHINE ===\n\n");
							printf("Creditos: %d\n",creditos);
							printf("Quanto quer apostar: ");
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
							fimaposta(aposta,creditos,&opslot);
							guardarcreditos(creditos,notificacoes,autosave);
						}while(opslot==1);
					}while(opslot!=3);
					system("cls");
					;break;
			case 2: do{
						do{
							system("cls");
							printf("=== BLACKJACK ===\n\n");
							printf("Creditos: %d\n",creditos);
							printf("Quanto quer apostar: ");
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
							if(cartas(numjogador1)=="A")
								maojogador=maojogador+10;
							if(cartas(numjogador2)=="A")
								maojogador=maojogador+10;
							printf("\nTotal: %d\n\n",maojogador);
							printf("Cartas da mesa:\n");
							printf("[ %s ] [ ? ] \n",cartas(nummesa1));
							maomesa=nummesa1;
							if(cartas(nummesa1)=="A")
								maomesa=maomesa+10;
							pedircarta=1;
							if(maojogador==21){
								printf("Black jack voce fez 21!!!");
								printf("Resultado:\n");
								printf("Ganhou a ronda +%d creditos\n",aposta*1.5);
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
									if(cartas(numjogador)=="A" && maojogador+10<21)
										maojogador=maojogador+10;	
									printf("\nTotal: %d\n\n",maojogador);						
								}
							}
							if(maojogador>21){
								printf("\n\nVoce estourou!!!!\n");
								printf("Resultado:\n");
								printf("Perdeu a ronda -%d creditos\n",aposta);
								creditos=creditos-aposta;
								lose=1;
							}
							if( lose==0){
							printf("mao mesa :\n [ %s ] [ %s ] \n",cartas(nummesa1),cartas(nummesa2));
							maomesa=nummesa1+nummesa2;
							printf("\nTotal da mesa: %d\n\n",maomesa);
							}
							if(maomesa==21 && lose==0){
								printf("Black jack Mesa fez 21!!!");
								printf("Resultado:\n");
								printf("Perdeu a ronda -%d creditos\n",aposta);
								creditos=creditos-aposta;
								lose=1;
							}
							numjogador=0;
							if(maomesa<17 && lose==0){
								for(;maomesa<21;maomesa=maomesa+numjogador){
									printf("Mesa pede carta...\n");
									numjogador=rand()%13+1;
									printf("[ %s ] ",cartas(numjogador));
									maomesa=maomesa+numjogador;
									if(cartas(numjogador)=="A" && maomesa+10<21)
										maomesa=maomesa+10;	
									printf("\nTotal da mesa: %d\n\n",maomesa);						
								}
							}
							if(maomesa>21 && lose==0){
								printf("\n\nMesa estourou!!!!\n");
								printf("Resultado:\n");
								printf("Ganhaste a ronda +%d creditos\n",aposta);
								creditos=creditos+aposta;
							}
							if(maomesa<maojogador ){
								printf("Resultado:\n");
								printf("Ganhaste a ronda +%d creditos\n",aposta);
								creditos=creditos+aposta;
								printf("Créditos atuais: %d",creditos);	
								}
							if(maomesa==maojogador && lose==0){
								printf("Empataste Com a mesa");
							}
							fimaposta(aposta,creditos,&opslot);
							guardarcreditos(creditos,notificacoes,autosave);
						}while(opslot==1);
					}while(opslot==2);
					system("cls");
					;break;
			case 3:	do{
						do{
							system("cls");
							printf("=== Azul VS Vermelho ===\n");
							printf("Creditos: %d\n",creditos);					
							printf("Quanto quer apostar: ");
							scanf("%d",&aposta);
							if(aposta>creditos){
								printf("\nAposta invalida, creditos insuficientes\n");
								getch();
							}
						}while(aposta>creditos);
						printf("Quer jogar no modo rapido?(s/n):");
						scanf(" %c",&modorapido);
						printf("\n\nEscolhe uma cor para apostar:\n");
						printf("1 - Azul\n");
						printf("2 - Vermelho\n");
						printf("3 - Verde (Empate)\n\n");
						printf("Escolha: ");
						scanf("%d",&opmenu);
						nummesa1=rand()%6+1;
						nummesa2=rand()%6+1;
						printf("\n\nVermelho jogar os dados...\n");
						printf("Dados Vermelho:\n [ %d ] [ %d ]\n",nummesa1,nummesa2);						
						vermelho=nummesa1+nummesa2;
						nummesa1=rand()%6+1;
						nummesa2=rand()%6+1;
						printf("\n\nAzul jogar os dados...\n");
						printf("Dados Azul:\n [ %d ] [ %d ]\n\n",nummesa1,nummesa2);						
						azul=nummesa1+nummesa2;
						switch(opmenu){
							case 1:
								if(azul>vermelho){
									printf("Resultado : Ganhaste!! +%d creditos\n",aposta);
									creditos=creditos+aposta;
									printf("Creditos atuais: %d",creditos);
								}
								else{
									if(azul==vermelho){
										printf("Resultado : Empate!! -%d creditos\n",aposta);
										creditos=creditos-aposta;
										printf("Creditos atuais: %d",creditos);
									}
									else{
										printf("Resultado : Perdeste!! -%d creditos\n",aposta);
										creditos=creditos-aposta;
										printf("Creditos atuais: %d",creditos);	
									}
								}
							break;
							case 2:
								if(vermelho>azul){
									printf("Resultado : Ganhaste!! +%d creditos\n",aposta);
									creditos=creditos+aposta;
									printf("Creditos atuais: %d",creditos);
								}
								else{
									if(azul==vermelho){
										printf("Resultado : Empate!! -%d creditos\n",aposta);
										creditos=creditos-aposta;
										printf("Creditos atuais: %d",creditos);
									}
									else{
										printf("Resultado : Perdeste!! -%d creditos\n",aposta);
										creditos=creditos-aposta;
										printf("Creditos atuais: %d",creditos);	
									}
								}
							break;
							case 3:
								if(azul>vermelho){
									printf("Resultado : Perdeste!! -%d creditos\n",aposta);
									creditos=creditos-aposta;
									printf("Creditos atuais: %d",creditos);
								}
								else{
									if(azul==vermelho){
										printf("Resultado : Empate!! +%d creditos\n",aposta*10);
										creditos=creditos+aposta*10;
										printf("Creditos atuais: %d",creditos);
									}
									else{
										printf("Resultado : Perdeste!! -%d creditos\n",aposta);
										creditos=creditos-aposta;
										printf("Creditos atuais: %d",creditos);	
									}
								}
							break;
						}
						do{
							printf("\n------------------------------------------------\n");
							printf("1 - Jogar outra vez\n");
							printf("2 - Voltar ao menu\n");
							printf("Escolhe uma opção:");
							scanf("%d",&opslot);
							if(aposta>creditos){
								printf("\nAposta invalida, creditos insuficientes\n");
								getch();
							}
						}while(aposta>creditos);
					}while(opmenu==2);
					system("cls");
					break;
			case 4: printf("Voce tem %d creditos\n",creditos);
					printf("Pressa qualquer tecla pra Continuar...");
					getch();
					break;
			case 5:	do{
						system("cls");
						printf("1 - Slot Machine\n");
						printf("2 - Blackjack\n");
						printf("3 - Menu\n");
						printf("Escolha: ");
						scanf("%d",&opmenu);
						switch(opmenu){
							case 1: printf("\n=== SLOT MACHINE ===\n\n");
									printf("Objetivo:\n");
									printf("Fazer 3 símbolos iguais.\n\n");
									printf("Como jogar:\n");
									printf("- Escolhe a aposta\n");
									printf("- Os rolos giram\n");
									printf("- Aparecem 3 símbolos\n\n");
									printf("Prémios:\n");
									printf("- 3 símbolos iguais -> ganhas 5x a aposta\n");
									printf("- 2 símbolos iguais -> ganhas 2x a aposta\n");
									printf("- Nenhum igual -> perdes a aposta\n");
									printf("Dica:\n");
									printf("Quanto maior a aposta, maior o prémio.\n");
									printf("Pressa qualquer tecla pra Continuar...");
									getch();
									;break;
							case 2:	printf("=== BLACKJACK ===\n\n");
									printf("Objetivo:\n");
									printf("Chegar o mais perto possível de 21 sem passar.\n\n");
									printf("Cartas:\n");
									printf("2 a 10 -> valem o número\n");
									printf("J, Q, K -> valem 10\n");
									printf("A -> vale 11 ou 1\n\n");
									printf("Como jogar:\n");
									printf("- Recebes 2 cartas\n");
									printf("- A mesa mostra 1 carta\n");
									printf("- Podes:\n");
									printf("  1 - Pedir carta\n");
									printf("  2 - Parar\n\n");
									printf("Regras:\n");
									printf("- Se passares de 21, perdes\n");
									printf("- A mesa joga depois de ti\n");
									printf("- A mesa pede cartas até ter 17\n\n");
									printf("Ganhas se tiveres mais pontos que a mesa sem passar de 21.\n");
									printf("Pressa qualquer tecla pra Continuar...");
									getch();
									break;
						}
					}while(opmenu!=3);
					system("cls");
					break;
				case 6:	do{
							system("cls");
							printf("=============BONUS============\n\n");
							printf("A cada 10 minutos ganhas 100 creditos\n");
							printf("1 - Recolher\n");
							printf("2 - SAIR\n");
							printf("Escolha:");
							scanf("%d",&opmenu);
							if(opmenu==1){						
								printf("Quer mesmo resetar seus creditos!!(s/n):");
								scanf(" %c",&sn);
								if(sn=='s' || sn=='S'){			
									creditos=100;
									printf("tens 100 creditos!\n");
									guardarcreditos(creditos,notificacoes,autosave);

								}
							}
							printf("\nPressa qualquer tecla pra Continuar...");
							getch();
						}while(opmenu!=2);
						break;
				case 7:	do{
							system("cls");
							configuracoes(autosave,notificacoes);
							printf("3 -  Voltar ao MENU \n");
							printf("Escolha:");
							scanf("%d",&opmenu);
							if(opmenu==1)
								autosave= !autosave;
							if(opmenu==2)
								notificacoes= !notificacoes;
							f=fopen("config.txt","w");
							fprintf(f,"%d\n%d",autosave,notificacoes);
							fclose(f);
						}while(opmenu!=3);
						
						break;
		}
	}while(opmenu!=8);
getch();
}
