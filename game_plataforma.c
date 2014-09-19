#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <dos.h>

void escrevePlayer(int xx, int yy, int axx, int ayy);
void preparaMundo(void);
void escreveTexto(int x, int y, char msg);
void mostra();
void preparaMapa();
//void mapaMovimenta();
void comeca();
void fim();
void pular();
//int testaVida();
//void morreu();
int trocaMostra3();
int trocaMapa3();

int tecla=0, X=9, Y=0, aX, aY, tamCalcada=10, tamRua=7, vidas=9, subir=0, descer=0, contSubiu, contDesceu;
int  trocaMapa=0, trocaMapa2=1, trocaMostra=0, trocaMostra2=800;
char mundo[10][30];
int aj[10], aj2[10];
clock_t start_t;
float mseg2=0, mseg=0;

//char mapa1[10][30] = {{'', ''}}

int main(void){
  
  system("MODE CON: COLS=31 LINES=12");
  vidas=9;
  comeca();
  
  return 0;
}

void comeca(){
  srand(time(NULL));
  preparaMundo();
  preparaMapa();
  escreveTexto(9, 0, 'x');
  escreveTexto(0, 27, 'V');
  escreveTexto(0, 28, ':');
  escreveTexto(0, 29, vidas);
  mostra();
  start_t = clock();
  
  while(0==0){
  	 if(!kbhit()){
	 	if(trocaMostra3()==1){
            if(X<9&&subir==0){
               aX=X;
		       aY=Y;
               X=X+1;
               escrevePlayer(X, Y, aX, aY);
            }
            if(X>6&&subir==1){
               aX=X;
		       aY=Y;
               X=X-1;
               escrevePlayer(X, Y, aX, aY);
               if(X==6){
                  subir=0;
               }
            }
	 		mostra();
	 		trocaMostra=0;
	 	}else{
	 		trocaMostra++;
	 	}
	 }else{
	 	tecla=getch();
	 	pular();
	 	if(tecla==77){
        	escreveTexto(9, 29, 'D');
     		if((Y<28)){
            	aX=X;
            	aY=Y;
            	Y=Y+1;
            	escrevePlayer(X, Y, aX, aY);
         	}	
     	}
     	if(tecla==75){
     		escreveTexto(9, 29, 'E');
     		if((Y>0)){
     	   		aX=X;
        		aY=Y;
        		Y=Y-1;
        		escrevePlayer(X, Y, aX, aY);
        	 }
     	}
     	if(tecla==72){
	        escreveTexto(9, 29, 'C');
     		if((X>=9)&&(subir==0)){
     			subir=1;
    	    }
      	}
 	    if(tecla==80){
             escreveTexto(9, 29, 'B');
     		/* if((X<9)){
        	     aX=X;
        		 aY=Y;
        		 X=X+1;
        		 escrevePlayer(X, Y, aX, aY);
    		  }*/
  	    }
     	if(trocaMostra3()==1){
             if(X<9&&subir==0){
               aX=X;
		       aY=Y;
               X=X+1;
               escrevePlayer(X, Y, aX, aY);
             }  
             if(X>=6&&subir==1){
               aX=X;
		       aY=Y;
               X=X-1;
               escrevePlayer(X, Y, aX, aY);
               if(X==6){
                  subir=0;
               }
             }            
			 mostra();
			 trocaMostra=0;
	 	}else{
	 		trocaMostra++;
	 	}
 	}
  }	
 // morreu();
}

int trocaMostra3(){	
	float te = (float)CLOCKS_PER_SEC/10000;
	mseg = mseg+te;
	mseg2 = mseg2+te;
	if(trocaMapa3()==1){
	//	mapaMovimenta();
	}
	if(mseg>5.0){
  		mseg=0.0;
		return 1;
	}else{
		return 0;
	}
}

int trocaMapa3(){
	if(mseg2>20.0){
		mseg2=0;
		return 1;
	}else{
		return 0;
	}
}
/*
int testaVida(){
	if(Y==aj[9]||Y==aj[9]+tamRua){
		return 1;
	}else{
		return 0;
	}
}

void morreu(){
	vidas--;
	if(vidas<0){
		escreveTexto(X, Y, 'x');
		mostra();
		printf("\nFim de Jogo!");
		getch();
		main();
	}else{
		printf("\n\nVoce Perdeu!");
		getch();
		comeca();
	}
}
*/
void preparaMapa(){
	
}
/*
void mapaMovimenta(){
	int i, j=aj[0];
	
	int dj=rand()%2;
	if(dj==0){
		if(j!=1){
			j--;
		}else{
			j++;
		}
	}else{
		if(j!=tamCalcada-2){
			j++;
		}else{
			j--;
		}
	}
	int x1, x2;
	for(i=0;i<10;i++){
		escreveTexto(i, aj[i], ' ');
		escreveTexto(i, aj2[i], ' ');
	}
	for(i=1;i<10;i++){
		if(i==1){
			x2=aj[0];
			aj[0]=j;
			x1=aj[i];
			aj[i]=x2;
		}else{
			x2=aj[i];
			aj[i]=x1;
			x1=x2;
		}
	}
	for(i=0;i<10;i++){
		escreveTexto(i, aj[i], '#');
	}
	for(i=0;i<10;i++){
		aj2[i]=aj[i]+tamRua;
		escreveTexto(i, aj2[i], '#');
	}
}
*/
void escreveTexto(int xx, int yy, char msg){
   mundo[xx][yy]=msg; 
}

void mostra(){
   system("cls");
   int i, j;
   for(i=0;i<10;i++){	
	  for(j=0;j<30;j++){
	  	 if(j==0&&i!=0){
	  	 	 printf("\n");
	  	 }
	  	 if(mundo[i][j]==0||mundo[i][j]==1||mundo[i][j]==2||mundo[i][j]==3||mundo[i][j]==4||mundo[i][j]==5||mundo[i][j]==6||mundo[i][j]==7||mundo[i][j]==8||mundo[i][j]==9){
	  	 	printf("%d", mundo[i][j]);
	  	 }else{
	  	 	 
			printf("%c", mundo[i][j]);
	  	 }
	  }
   }
}

void escrevePlayer(int xx, int yy, int axx, int ayy){
   mundo[xx][yy]='x';               
   mundo[axx][ayy]=' ';
}

void preparaMundo(void){
   
   int i, j;
   
   for(i=0;i<10;i++){
      for(j=0;j<30;j++){
       	mundo[i][j]=' ';  
      }
   }                  
   
   mostra();
}
