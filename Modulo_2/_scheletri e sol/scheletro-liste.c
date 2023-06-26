#include <stdio.h>
#include <stdlib.h>

/*****************************/
/********* STRUTTURE *********/
/*****************************/


/**************************************/
/*********** VISUALIZZAZIONE **********/
/**************************************/

/**********************************************
 **************** RICERCA *********************
 **********************************************/

/**********************************************
 ********** CANCELLAZIONE ************************
 **********************************************/

/**********************************************
 ********** INSERIMENTO ************************
 **********************************************/


/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main() {
	/* inizializza la lista */


	int risposta = -1;			// per interazione con utente

	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Visualizzazione\n");
		printf("2 -> Ricerca\n");
		printf("3 -> Cancellazione\n");
		printf("4 -> Inserimento\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);

		/* gestisci le operazioni dell'utente */
		if(risposta==1)

		else if(risposta==2)

		else if(risposta==3)

		else if(risposta==4)

		else if(risposta==0)
			printf("Finito!\n\n");

		else printf("Selezione non valida!\n\n");
	}
}