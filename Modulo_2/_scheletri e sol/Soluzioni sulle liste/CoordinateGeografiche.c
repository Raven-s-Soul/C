#include <stdio.h>
#include <stdlib.h>

struct Coordinata {
	float longitudine;
	float latitudine;
};

struct Nodo {
	struct Coordinata c;
	struct Nodo *next;
};

typedef struct Coordinata COORD;
typedef struct Nodo* NODO;

/*********************************************************
 ************************ STAMPA **************************
 *********************************************************/

/* per stampare una coordinata */
void stampaCoordinata(COORD c) {
	printf("Longitudine: %f%c, Latitudine: %f%c\n", c.longitudine,167,c.latitudine,167);
}

/* per stampare la lista */
void stampaLista(NODO head) {
  NODO nodo;
  nodo = head->next; 		//supero il primo nodo fittizio
	if(nodo==NULL)
		printf("Lista vuota!\n\n");
	else {
		int i=1;
		printf("**************\n");
		printf("Ecco la lista: \n");
		printf("**************\n");
		while(nodo != NULL) {
			printf("Coordinata %d: ", i);
			stampaCoordinata(nodo->c);
			i++;
			nodo = nodo->next;
		}
		printf("**************\n\n");
	}
}

/*********************************************************
 ************************ INSERIMENTO *********************
 *********************************************************/

/* per leggere una coordinata geografica */
COORD leggiCoordinata() {
	COORD c;			// da leggere
	printf("Introduci la longitudine: ");
	scanf("%f", &c.longitudine);
	printf("Introduci la latitudine: ");
	scanf("%f", &c.latitudine);
	return c;
}


/* funzione che inserisce un nodo in coda alla lista */
void inserimento(NODO head) {
	NODO nuovoNodo; 										// il nuovo nodo della lista
	nuovoNodo = malloc(sizeof(struct Nodo)); 		// allocazione nuovo nodo nell'heap

	/* riempi i campi del nuovo nodo */
	nuovoNodo->c = leggiCoordinata();
	nuovoNodo->next = NULL;

	/* collega il nodo al precedente: devi cercare l'ultimo nodo della lista, che potrebbe
	 * anche essere quello fittizio */
	while(head->next != NULL) 		// l'ultimo nodo ha il campo next vuoto
		head=head->next;					// scorri di 1

	/* ora head contiene l'indirizzo dell'ultimo nodo della lista */
	head->next = nuovoNodo;
	printf("Inserimento effettuato!\n\n");
}


/*********************************************************
 ************************ CANCELLAZIONI *******************
 *********************************************************/

/* funzione che cancella un nodo dalla testa della lista */
void cancellazione(NODO head) {
	NODO nodo;					// di appoggio

	/* se lista non � vuota devi cancellare */
	if(head->next!=NULL){
		nodo = head->next; //devo ricordare l'indirizzo del nodo da cancellare per deallocarlo
		head->next=nodo->next;
		free(nodo);
		printf("Cancellazione effettuata!\n\n");
	}
	else
		printf("Niente da cancellare!\n\n");
}


/*********************************************************
 ************************ MAIN ****************************
 *********************************************************/

/* funzione principale */
int main() {
	int risposta = -1;										// valore inserito dall'utente
	NODO head = malloc(sizeof(struct Nodo)); 	// lista con nodo fittizio
  head->next=NULL;

	/* ciclo di interazione con l'utente */
	while(risposta!=0) {
		printf("Che operazione vuoi svolgere?\n");
		printf("Introduci 1 -> Immetti una coordinata in coda alla lista\n");
		printf("Introduci 2 -> Cancella la prima coordinata della lista\n");
		printf("Introduci 3 -> Visualizza la lista\n");
		printf("Introduci 0 -> Termina il programma\n");
		scanf("%d%*c", &risposta);

		/* Inserimento in testa */
		if(risposta==1)
			inserimento(head);
		/* Cancellazione in coda */
		else if(risposta==2)
			cancellazione(head);
		/* Visualizzazione */
		else if(risposta==3) {
			stampaLista(head);
		}
		/* numero sbagliato? */
		else  if(risposta!=0)
			printf("Questo numero non vuol dire niente. Riproviamo!\n\n");
	}
}
