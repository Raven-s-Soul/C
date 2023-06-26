#include <stdio.h>

/* funzione che verifica, all'interno di un array di interi ricevuto 
 * come parametro, se ogni tripla di interi adiacenti nell'array contiene 
 * almeno due interi maggiori o uguali a 10, di cui esattamente uno pari */
int esattamenteUnoPariGrande(int* seq, int lungh) {
	int tutti;				// risultato 
	
	/* caso base */
	if(lungh<=2)
		tutti = 1;
	/* passo ricorsivo */
	else
		tutti = ((seq[0]>=10 && seq[1]>=10 && ((seq[0]+seq[1])%2!=0)) || 
				 (seq[0]>=10 && seq[2]>=10 && ((seq[0]+seq[2])%2!=0)) ||
				 (seq[1]>=10 && seq[2]>=10 && ((seq[1]+seq[2])%2!=0)))
				 && esattamenteUnoPariGrande(seq+1,lungh-1);
	return tutti;
}

/* funzione principale */
int main(int argc, char **argv)
{
	/* input */
	int lunghezza;
	printf("Quanti interi vuoi introdurre?\n");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("Dammi un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	/* output */
	if(esattamenteUnoPariGrande(sequenza,lunghezza))
		printf("Ogni tripla contiene due interi grandi di cui esattamente uno pari\n");
	else
		printf("Non ogni tripla contiene due interi grandi di cui esattamente uno pari\n");
		
}
