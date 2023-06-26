#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int numero;
	struct Nodo *next;
};

/*********************************************************
 ************************ STAMPA **************************
 *********************************************************/ 

void stampaLista(struct Nodo* head) {
	struct Nodo *nodo = head;	// primo elemento della lista
	/* lista vuota? */
	if(nodo==NULL)
		printf("La lista non contiene elementi!\n\n");
	else {
		printf("Ecco la lista: ");
		/* stampa ciascun elemento della lista */
		while(nodo != NULL) {
			printf("%d ", nodo->numero);
			nodo = nodo -> next;
		}
		printf("\n\n");
	}
}

/*********************************************************
 ************************ INSERIMENTI *********************
 *********************************************************/ 

/* funzione che inserisce un nodo in testa alla lista: restituisce l'indirizzo del nuovo 
 * primo elemento della lista */		
struct Nodo *inserisciNodo(struct Nodo *head) {
	struct Nodo *nuovoNodo;											// il nuovo nodo della lista
	nuovoNodo = malloc(sizeof(struct Nodo)); 				// allocazione nodo nell'heap
	
	/* leggi il campo dati */
	printf("Inserisci l'intero!\n");
	scanf("%d", &(nuovoNodo -> numero)); 							
	printf("\n");
	
	/* collega il nodo al successivo */
	nuovoNodo->next = head;								
	
	printf("Inserimento effettuato!\n\n");
	
	/* restituisci l'indirizzo del nuovo primo elemento */
	return nuovoNodo;								
}

/* funzione che inserisce un nodo in testa alla lista */		
void inserisciNodo2(struct Nodo **puntaHead) {
	struct Nodo *nuovoNodo;											// il nuovo nodo della lista
	nuovoNodo = malloc(sizeof(struct Nodo)); 				// allocazione nodo nell'heap
	
	/* leggi il campo dati */
	printf("Inserisci l'intero!\n");
	scanf("%d", &(nuovoNodo -> numero)); 							
	
	/* collega il nodo al successivo; tramite *puntaHead accediamo al valore puntato da 
	 * puntaHead, ovvero al contenuto della variabile head nel main, ovvero all'indirizzo 
	 * del precedente primo nodo della lista */
	nuovoNodo->next = *puntaHead;											
	
	printf("Inserimento effettuato!\n\n");

	/* collega il nodo alla testa */
	*puntaHead = nuovoNodo;								
}

/* funzione che inserisce un nodo in coda alla lista: restituisce l'indirizzo del nuovo 
 * primo elemento della lista */		
struct Nodo *inserisciCoda(struct Nodo *head) {
	struct Nodo *nuovoNodo;									// il nuovo nodo della lista
	nuovoNodo = malloc(sizeof(struct Nodo)); 		// allocazione nuovo nodo nell'heap

	/* riempi i campi del nuovo nodo */
	printf("Inserisci l'intero!\n");
	scanf("%d", &(nuovoNodo -> numero)); 							
	printf("\n");
	nuovoNodo->next = NULL;
	
	/* collega il nodo al precedente */
	if(head == NULL) 		// lista vuota? 
		head = nuovoNodo;		// il nuovo nodo diventa il primo
	else{							// lista non vuota, cerca l'ultimo nodo
		struct Nodo *nodoCorrente = head;
		while(nodoCorrente->next != NULL)
			nodoCorrente = nodoCorrente->next;
		/* ora nodoCorrente è l'indirizzo dell'ultimo nodo della lista */
		nodoCorrente->next = nuovoNodo;							
	}
	
	printf("Inserimento effettuato!\n\n");

	return head;	// nota che se la lista non è vuota è già tutto a posto
}

/* funzione che inserisce un nodo in coda alla lista */		
void inserisciCoda2(struct Nodo **puntaHead) {
	struct Nodo *nuovoNodo;									// il nuovo nodo della lista
	nuovoNodo = malloc(sizeof(struct Nodo)); 		// allocazione nuovo nodo nell'heap

	/* riempi i campi del nuovo nodo */
	printf("Inserisci l'intero!\n");
	scanf("%d", &(nuovoNodo -> numero)); 							
	printf("\n");
	nuovoNodo->next = NULL;
	
	/* collega il nodo al precedente */
	if(*puntaHead == NULL) 		// lista vuota? 
		*puntaHead = nuovoNodo;		// il nuovo nodo diventa il primo
	else{							// lista non vuota, cerca l'ultimo nodo
		struct Nodo *nodoCorrente = *puntaHead;
		while(nodoCorrente->next != NULL)
			nodoCorrente = nodoCorrente->next;
		/* ora nodoCorrente è l'indirizzo dell'ultimo nodo della lista */
		nodoCorrente->next = nuovoNodo;							
	}

	printf("Inserimento effettuato!\n\n");
}

/*********************************************************
 ************************ CANCELLAZIONI *******************
 *********************************************************/ 

/* funzione che cancella un nodo dalla testa della lista: restituisce l'indirizzo del nuovo 
 * primo elemento della lista */		
struct Nodo *cancellaNodo(struct Nodo *head) {
	struct Nodo *primoNodo;											// il nuovo primo nodo della lista
	
	/* lista vuota? */
	if(head==NULL) {
		primoNodo = NULL;
		printf("Niente da cancellare!\n\n");
	}
	else {
		/* il secondo nodo diventa il primo; eventualmente questo è NULL */
		primoNodo = head->next;
		/* viene deallocata la memoria del primo nodo */
		free(head);
		printf("Cancellazione effettuata!\n\n");
	}
	
	/* restituisci l'indirizzo del nuovo primo elemento */
	return primoNodo;								
}

/* funzione che cancella un nodo dalla testa della lista */		
void cancellaNodo2(struct Nodo **puntaHead) {
	struct Nodo *primoNodo;											// il nuovo primo nodo della lista
	
	/* se la lista è vuota non fare niente */
	if(*puntaHead!=NULL) {
		/* vuoi l'indirizzo del secondo nodo, in quanto il secondo nodo sarà il nuovo primo nodo; 
		 * tale indirizzo è memorizzato nel campo next del primo nodo; per accedere al campo next
		 * del primo nodo, accediamo al puntatore al primo nodo (variabile head in main), tramite
		 * il nostro puntatore a head, e quindi al campo tramite l'operatore -> */
		primoNodo = (*puntaHead)->next;
		/* viene deallocata la memoria del primo nodo */
		free(*puntaHead);
		/* nuova testa della pila */
		*puntaHead = primoNodo;
		printf("Cancellazione effettuata!\n\n");
	}
	else
		printf("Niente da cancellare!\n\n");
}

/* funzione che cancella il primo nodo con un certo valore: restituisce l'indirizzo 
 * del nuovo primo elemento della lista */		
struct Nodo *cancellaValore(struct Nodo *head, int valore) {
	struct Nodo *nodo;					// nodo generico della lista
	struct Nodo *nodoPrec;			// nodo precedente a quello sopra
	
	/* se la lista è vuota non devi fare niente */
	if(head!=NULL) {
		/* se il nodo da cancellare è il primo, allora head cambia */
		if(head->numero == valore) { 
			nodo = head;					// da deallocare
			head = head->next;		// il secondo diventerà il primo
			free(nodo);					// dealloca il nodo
			printf("Cancellazione effettuata!\n\n");
		}
		else {	// il nodo da cancellare non è il primo
			int cancellato = 0;					// hai finito?		
			/* cerca il nodo 	con il valore dato */
			nodo = head->next;			// controlla il secondo
			nodoPrec = head;				// setta il precedente
			while(nodo != NULL && !cancellato) {
				/* trovato? */
				if(nodo->numero == valore) {
					nodoPrec->next = nodo->next; 		// il next del precedente diventa il successivo 
					free(nodo);									// dealloca il nodo
					cancellato = 1;
					printf("Cancellazione effettuata!\n\n");
				}
				else {	// passa al prossimo
					nodoPrec = nodo;
					nodo = nodo->next;
				}
			}
			if(!cancellato)
				printf("Nessun elemento col valore richiesto!\n\n");
		}
	}
	else
		printf("Niente nodi in lista!\n\n");
	
	return head;	// se l'elemento cancellato non è il primo è già tutto a posto
}

/* funzione che cancella il primo nodo con un certo valore */		
void cancellaValore2(struct Nodo **puntaHead, int valore) {
	struct Nodo *nodo;					// nodo generico della lista
	struct Nodo *nodoPrec;			// nodo precedente a quello sopra
	
	/* se la lista è vuota non devi fare niente */
	if(*puntaHead!=NULL) {
		/* se il nodo da cancellare è il primo, allora head cambia */
		if((*puntaHead)->numero == valore) { 
			nodo = *puntaHead;							// da deallocare
			*puntaHead = (*puntaHead)->next;		// il secondo diventerà il primo
			free(nodo);					// dealloca il nodo
			printf("Cancellazione effettuata!\n\n");
		}
		else {	// il nodo da cancellare non è il primo
			int cancellato = 0;					// hai finito?		
			/* cerca il nodo 	con il valore dato */
			nodo = (*puntaHead)->next;			// controlla il secondo
			nodoPrec = *puntaHead;					// setta il precedente
			while(nodo != NULL && !cancellato) {
				/* trovato? */
				if(nodo->numero == valore) {
					nodoPrec->next = nodo->next; 		// il next del precedente diventa il successivo 
					free(nodo);									// dealloca il nodo
					cancellato = 1;
					printf("Cancellazione effettuata!\n\n");
				}
				else {	// passa al prossimo
					nodoPrec = nodo;
					nodo = nodo->next;
				}
			}
			if(!cancellato)
				printf("Nessun elemento col valore richiesto!\n\n");
		}
	}
	else
		printf("Niente nodi in lista!\n\n");
}

/*********************************************************
 ************************ LUNGHEZZA **********************
 *********************************************************/ 

/* funzione che calcola il numero di elementi di una lista */
int lunghezza(struct Nodo* head) {
	struct Nodo *nodo = head;		// nodo generico
	int lunghezza = 0;					// valore da calcolare
	
	/* vai avanti finchè ci sono altri nodi */
	while(nodo != NULL) {				
		lunghezza++;
		nodo = nodo->next;		// passa al prossimo
	}
	return lunghezza;
}

/*********************************************************
 ************************ MASSIMO ************************
 *********************************************************/ 

/* relazione d'ordine fra due nodi, restituisce 1 se il primo è maggiore del secondo */
int maggiore(struct Nodo *nodo1, struct Nodo *nodo2) {
	int risultato;
	if((nodo1->numero) > (nodo2->numero))
		risultato = 1;
	else
		risultato = 0;
	return risultato;
}

/* calcola elemento massimo nella lista */
struct Nodo* massimo(struct Nodo *head) {
	// pre: almeno un nodo nella lista
	struct Nodo *massimo = head;			// inizialmente il massimo è il primo nodo
	struct Nodo *nodo = head->next;		// parti dal secondo nodo
	/* vai avanti fino a che ci sono elementi */
	while(nodo!= NULL) {
		if(maggiore(nodo,massimo)) 
			massimo = nodo;
		nodo = nodo->next;
	}
	return massimo;
}	

/*********************************************************
 ************************ ORDINAMENTO ********************
 *********************************************************/ 

/* funzione che ordina gli elementi di una lista; implementa selection sort */
void ordinaLista(struct Nodo *head) {
	struct Nodo *primo;			// primo nodo parte non ordinata
	struct Nodo *minimo;			// minimo corrente
	struct Nodo *nodo;				// nodo corrente
	int temp;							// variabile ausiliaria
	
	/* il primo nodo non ordinato è il primo nodo della lista */
	primo = head;					
	/* prosegui fino a che il primo nodo da ordinare è NULL */
	while(primo!=NULL) {
		/* inizializza il minimo a primo */
		minimo = primo;
		/* guarda tutti i nodi a partire dal successivo a primo e prosegui fino a 
		 * che non li hai visti tutti */
		for(nodo = primo->next; nodo!=NULL; nodo = nodo -> next) 
			/* minore del minimo ? */
			if(nodo->numero < minimo->numero) 
				minimo = nodo;

		/* adesso scambia i campi dati del minimo e del primo elemento non ordinato */
		temp = primo->numero;
		primo->numero = minimo->numero;
		minimo->numero = temp;
		
		/* fai scorrere il primo elemento non ordinato */
		primo = primo->next;
	}
	printf("Lista ordinata!\n\n");
}

/*********************************************************
 ************************ MAIN ****************************
 *********************************************************/ 

/* funzione principale */
int main() {
	int risposta = -1;					// valore inserito dall'utente
	struct Nodo *head = NULL; 		// lista inizialmente vuota
	
	/* ciclo di interazione con l'utente */
	while(risposta!=0) {
		printf("Che operazione vuoi svolgere?\n");
		printf("Introduci 1 -> Immetti un intero in testa alla lista\n");
		printf("Introduci 2 -> Immetti un intero in coda alla lista\n");
		printf("Introduci 3 -> Cancella il primo nodo della lista\n");
		printf("Introduci 4 -> Cancella un valore dalla lista\n");
		printf("Introduci 5 -> Visualizza la lista\n");
		printf("Introduci 6 -> Visualizza la lunghezza della lista\n");
		printf("Introduci 7 -> Visualizza il massimo della lista\n");
		printf("Introduci 8 -> Ordina la lista\n");
		printf("Introduci 0 -> Termina il programma\n");
		scanf("%d%*c", &risposta);

		/* Inserimento in testa */
		if(risposta==1) 
			head = inserisciNodo(head);
		/* Inserimento in coda */
		else if(risposta==2) 
			inserisciCoda2(&head);
		/* Cancellazione in testa */
		else if(risposta==3) { 
			cancellaNodo2(&head);
			printf("\n");
		}
		/* Cancellazione valore */
		else if(risposta==4) {
			int valore;			// valore da cancellare
			printf("Che valore vuoi cancellare?\n");
			scanf("%d%*c", &valore);
			cancellaValore2(&head, valore);
			printf("\n");
		}
		/* Visualizza la lista */
		else if(risposta==5) 
			stampaLista(head);
		/* Visualizza la lunghezza della lista */
		else if(risposta==6) 
			printf("La lista contiene %d elementi\n\n", lunghezza(head));
		/* Visualizza il massimo della lista */
		else if(risposta==7) {
			if(head==NULL) 
				printf("Lista vuota!\n\n");
			else {
				struct Nodo *nodo = massimo(head);
				printf("Il massimo nella lista vale %d\n\n", nodo->numero);
			}
		}
		/* Ordina la lista */
		else if(risposta==8) { 
			ordinaLista(head);
			printf("\n");
		}
		/* numero sbagliato? */
		else  if(risposta!=0)
			printf("Questo numero non vuol dire niente. Riproviamo!\n\n");
	}
}	