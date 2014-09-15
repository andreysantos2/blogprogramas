#include<stdio.h>
#include<stdlib.h>

void main(){
	
	int a[9], i, j, cont;
	printf("Digite 9 numeros: ");
	for(i=0;i<9;i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<9;i++){
		cont=0;
		for(j=1;j<=a[i];j++){
 	         if(a[i]%j==0)
 	        	cont++;
		}
 	   	if(cont==2)      
	 	    printf("O numero %d de indice %d eh primo\n", a[i], i);
	}
	
	getch();
	return;
}
