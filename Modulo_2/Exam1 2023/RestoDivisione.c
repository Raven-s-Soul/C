/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............6.7
*/
//Array

/*
	SPECIFICA
	input: Una sequenza di interi.  //**** MANCA LA LUNGHEZZA -0.2
	pre-condizione: almeno una tripla di elementi presi come input.
	output: una affermazione positiva o negativa. //**** UN BOOLEANO -0.1
	post-condizione: affermazione positiva se in una terna di numeri, uno dei tre è il resto degli altri due, altrimenti affermazione negativa.
	tipo di problema: verifica esistenziale.
*/

#include <stdio.h>

int restoDivisione(int *array, int len);

int main(){
	int len; //lunghezza array
	printf("Specificare dimensione array: ");
	scanf("%d",&len);
	int array[len];
	for(int i = 0; i < len; i++){
		printf("%d numero: ",i+1);
		scanf("%d", &array[i]);
	}
	int res = restoDivisione(array,len);
	if(res)
		printf("Istanza Positiva");  //**** OUTPUT PRATICAMENTE INESISTENTE -1
	else
		printf("Istanza Negativa");
}

int restoDivisione(int *array, int len){
	int condizione = 0;
	for(int i = 0 ; (i < len -2 ) && !condizione; i++){
		if( (array[i] == (array[i+1] / array[i+2]) || (array[i] == (array[i+2] / array[i+1]))) ||
			(array[i+1] == (array[i] / array[i+2]) || (array[i+1] == (array[i+2] / array[i]))) ||
			(array[i+2] == (array[i+1] / array[i]) || (array[i+2] == (array[i] / array[i+1]))) )
			//***** %, NON / -2
			condizione = 1;
	}

	return condizione;
}