/*
Autor: Andrey
Blog: http://programasdevcpp.blogspot.com.br/
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int op = 0, tecla, sair=0;
	//crio uma variavel para mostrar as opçoes e inicializo elas
	char ops[4] = {'*', ' ', ' ', ' '};
	//opção 3 vai ser usada para fechar o programa
	while(sair==0){
		//limpo toda vez que passa pelo laço para atualizar a tela
		system("cls");
		//crio a interface
		printf("###################\n");
		printf("#    [%c]Opcao 1   #\n", ops[0]);
		printf("#    [%c]Opcao 2   #\n", ops[1]);
		printf("#    [%c]Opcao 3   #\n", ops[2]);
		printf("#    [%c]Sair      #\n", ops[3]);
		printf("###################");
		//e pego a tecla cima ou baixo com a função getch() e armazeno em uma variavel tipo int
		tecla = getch();
		//agr comparo com um if qual é a tecla que foi apertada
		if(tecla==72){
			//código correspondente a tecla para cima
			if(op>=1){
				ops[op]= ' ';
				op=op-1;
				ops[op]= '*';
			}
		}
		if(tecla==80){
			//código correspondente a tecla para baixo
			if(op<=2){
				ops[op]= ' ';
				op=op+1;
				ops[op]= '*';
			}
		}
		//quando a pessoa apertar o enter eu verifico em qual opção ela esta e mando ela para a opção desejada
		if(tecla==13){
			switch(op){
				case 0: system("cls"); printf("Opcao Selecionada: Opcao 1\n"); getch();
					break;
				case 1: system("cls"); printf("Opcao Selecionada: Opcao 2\n"); getch();
					break;
				case 2: system("cls"); printf("Opcao Selecionada: Opcao 3\n"); getch();
					break;
				case 3: system("cls"); printf("Opcao Selecionada: Sair\n"); sair=1;
					break;
			}
		}
	}
	
	return 0;
}
