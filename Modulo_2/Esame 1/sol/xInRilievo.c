#include <stdio.h>
#include <string.h>

/* funzione che modifica una stringa lasciando solo le X
 * e separando ogni sequenza di X dalla successiva con uno spazio */
void xInRilievo(char* stringa) {
	int i = 0; 				// per scandire la stringa
	
	/* guarda tutti i caratteri della stringa */
	while(stringa[i]!='\0') {
		/* non toccare le X */
		if(stringa[i]=='X')
			i++;
		/* altrimenti non e' una X */
		else {
			/* cancella */
			if(i==0 || stringa[i+1]!='X')
				for(int j=i; stringa[j]!='\0'; j++)
					stringa[j]=stringa[j+1];
			/* rimpiazza con uno spazio */
			else {
				stringa[i]=' ';
				i++;
			}
		}
	}
} 

/* funzione principale */ 
int main(int argc, char **argv)
{
	/* input */
	char stringa[50];
	printf("Introduci una stringa: ");
	fgets(stringa,50,stdin);
	stringa[strlen(stringa)-1]='\0';
	
	/* modifica e output */
	xInRilievo(stringa);
	printf("Ecco la stringa modificata: %s\n", stringa);
}
