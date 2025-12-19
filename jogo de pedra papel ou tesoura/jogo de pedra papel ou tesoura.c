#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void mostrarMenu(int *vitorias, int *derrotas){
	printf("\nJogo: Pedra, Papel e Tesoura\n\n");
	printf("O placar está: tu %d x %d computador\n",*vitorias,*derrotas);
	printf("====================================\n\n");
	printf("Escolha uma opçao:\n\n");
	printf("1 - Pedra\n\n");
	printf("2 - Papel\n\n");
	printf("3 - Tesoura\n\n");
	printf("4 - Sair\n\n");
}
void escolhadojogador(int *op,int *vitorias,int *derrotas){
	int repete=0;
	do{
		printf("Digite sua escolha:");
		scanf("%d",op);
		printf("Voce escolheu: ");
		switch (*op){
			case 1:printf("Pedra\n");break;
			case 2:printf("Papel\n");break;
			case 3:printf("Tesoura\n");break;
			case 4:
				system("cls");
				printf("O placar final ficou: tu %d x %d computador\n",*vitorias,*derrotas);
				if(*vitorias==*derrotas)
					printf("Empatou com o computador!!\n");
				else{
					if(*vitorias>*derrotas)
						printf("Ganhou do computador!!!\nPARABENS!!!!!\n");
					else
						printf("Perdeu para o computador!");
				}
				system("pause");
				exit(0);break;
		}
	  } while(*op < 1 || *op > 4);
}
int main()
{
setlocale(LC_ALL,"Portuguese");
	int cp,op,vitorias=0,derrotas=0;
	srand(time(NULL));
	do{
		mostrarMenu(&vitorias, &derrotas);
		escolhadojogador(&op, &vitorias, &derrotas);
		cp=rand()%3+1;
		printf("computador escolheu: ");
		switch (cp){
			case 1:printf("Pedra\n");break;
			case 2:printf("Papel\n");break;
			case 3:printf("Tesoura\n");break;
		}
		if (cp==op)
			printf("Empate!\n");
		else{
			printf("Voce ");
			switch (op){
				case 1:
					if(cp==2){
						printf("Perdeu!!\n");
						derrotas++;
					}
					else{
						printf("Ganhou!!\n");
						vitorias++;
					}
				;break;
				case 2:
					if(cp==3){
						printf("Perdeu!!\n");
						derrotas++;
					}
					else{
						printf("Ganhou!!\n");
						vitorias++;
					}
				;break;
				case 3:
					if(cp==1){
						printf("Perdeu!!\n");
						derrotas++;
					}
					else{
						printf("Ganhou!!\n");
						vitorias++;
					}
				;break;
			}
		}
		system("pause");
		system("cls");
	}
	while(op!=4);
	getchar();
}
