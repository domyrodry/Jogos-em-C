#include<stdio.h>
#include<locale.h>
#include <string.h>
main()
{
setlocale(LC_ALL,"Portuguese");
	int i,j,resposta,acertos=0,erros=0;
	char *pergunta[] ={
	 "Qual é a capital de Portugal?",
	 "Quanto é 5 + 3?",
	 "Qual destes é um sistema operativo?",
	 "Em C, qual símbolo termina uma instrução?",
	 "Qual destes é um tipo de dados em C?",
	 "Para que serve o while?",
	};
	char *opcoes[] ={
		"Porto",
		"Lisboa",
		"Coimbra",
		"Faro",
		"6",
		"7",
		"8",
		"9",
		"Chrome",
		"Windows",
		"Windows",
		"Intel",
		":",
		";",
		",",
		".",
		"number",
		"text",
		"int",
		"string",
		"Guardar numeros",
		"Repetir codigo",
		"Criar variaveis",
		"mostrar texto",
		};
	char *opcaocorreta[]={
		"Lisboa",
		"8",
		"Windows",
		";",
		"int",
		"Repetir codigo",
		};
	for(i=0;i<=5;i++){
		printf("==========QUIZ==========\n\n");
		printf("Acertos: %d\n",acertos);
		printf("Erros: %d\n",erros);
		printf("Pergunta %d\n\n",i+1);
		printf("%s\n", pergunta[i]);
		for(j=i*4;j<i*4+4;j++){
			printf("%d - ",j-i*4+1);
			printf("%s\n", opcoes[j]);	
		}
		printf("Escolha uma opção: ");
		scanf("%d",&resposta);
		if(strcmp(opcoes[resposta+i*4-1], opcaocorreta[i])== 0){
			printf("Resposta esta correta!!\n");
			acertos++;
		}
		else{
			printf("Resposta esta incorreta!!!!\n");
			erros++;
		}
		system("pause");
		system("cls");
	}
getchar();
}
