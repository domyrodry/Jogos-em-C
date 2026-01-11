#include <stdio.h>
#include <locale.h>
#include <windows.h>
int simbolos(int num,char *slot){
			switch(num){		
				case 1:	*slot='B';
						return 15;	
				case 2:	*slot='C';
						return 10;
				case 3:	*slot='L';
						return 5;
				case 4:	*slot='S';
						return 30;
				case 5:	*slot='E';
						return 50;
				case 6:	*slot='D';
						return 100;
				case 7:	*slot='7';
						return 300;
								}
}
int main()
{
setlocale(LC_ALL,"Portuguese");
	int opmenu,creditos=100,jogos=0,aposta,num1,num2,num3,opslot,premio;
	char modorapido,slot1,slot2,slot3;
	srand(time(NULL));
	do{
		printf("=== MENU ===\n");
		printf("1 - Jogar\n");
		printf("2 - Ver creditos\n");
		printf("3 - Tutorial\n");
		printf("4 - Sair\n");
		printf("Escolha:");
		scanf("%d",&opmenu);
		switch (opmenu){
			case 1:
					do{
						system("cls");
						printf("=== SLOT MACHINE ===\n\n");
						printf("Creditos: %d\n",creditos);
						printf("Quanto quer apostar(0 pra sair): ");
						scanf("%d",&aposta);
						printf("Quer jogar no modo rapido?(s/n):");
						scanf(" %c",&modorapido);
						do{
							num1=rand()%7+1;
							num2=rand()%7+1;
							num3=rand()%7+1;
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
							premio=simbolos(num1,&slot1);
							simbolos(num2,&slot2);
							simbolos(num3,&slot3);
							printf("%c |%c | %c\n",slot1,slot2,slot3);
							printf("Resultado: ");
							if(num1==num2 && num2==num3){
								creditos=creditos+(aposta*premio);
								printf(" Ganhaste!! +%d creditos\n",aposta*premio);
							}
							else{
								creditos=creditos-aposta;
								printf(" Perdeste!! -%d Creditos\n",aposta);
							}
							printf("1 - Jogar outra vez com a mesma aposta\n");
							printf("2 - Mudar valor da aposta/mudar velocidade\n");
							printf("3 - Voltar ao menu\n");
							printf("Escolhe uma opção:");
							scanf("%d",&opslot);
							if(opslot==3){
							aposta=0;
							}
						}while(opslot!=3);
					}while(aposta!=0);
					system("cls");
					;break;
			case 2: printf("Voce tem %d creditos\n",creditos);break;
			case 3:	system("cls");
					printf("\nCOMO JOGAR AO SLOT\n");
					printf("\nObjetivo:\n");
					printf("Ganhar créditos fazendo 3 símbolos iguais numa jogada.\n");
					printf("\nSímbolos e creditos:\n");
					printf("B = Banana - 15 creditos\n");
					printf("C = Cereja - 10 creditos\n");
					printf("L = Limão - 5 creditos\n");
					printf("S = Sino - 30 creditos\n");
					printf("E = Estrela - 50 creditos\n");
					printf("D = Diamante - 100 creditos\n");
					printf("7 = Sete - 300 creditos\n");
					printf("\nComo jogar:\n");
					printf("1. Escolhe Jogar no menu.\n");
					printf("2. Escolhe quanto queres apostar nessa jogada.\n");
					printf("3. Escolhe se queres jogar no **modo rápido**:\n");
					printf(" - 's' - os rolós giram rapidamente, sem animação\n");
					printf(" - 'n' - os rolós giram lentamente, com pontos e pausas\n");
					printf("4. O programa mostra 3 símbolos aleatórios.\n");
					printf("5. Se forem 3 iguais, ganhas pontos multiplicados pela tua aposta.\n");
					printf("6. Se forem diferentes, perdes a aposta.\n");
					printf("\nDicas:\n");
					printf("- Quanto mais apostares, maior pode ser o prémio.\n");
					printf("- Símbolos valiosos como D ou 7 dão ainda mais pontos.\n");
					printf("- Continua a jogar enquanto tiveres créditos.\n");
					printf("- Podes ver os créditos no menu a qualquer momento.\n");
					printf("Prima qualquer tecla pra voltar ao menu:");
					printf("- O **modo rápido** permite rodar sem esperar pelas animações.");
					getch();
					system("cls");
					break;
		}
	}while(opmenu!=4);
getch();
}
