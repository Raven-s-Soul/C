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
	struct Nodo *nodo = head->next;		// salta il nodo fittizio
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

/* Funzione che inserisce un nodo in testa alla lista. */		
void inserisciNodo3(struct Nodo *head) {
	struct Nodo *app;							    // il nuovo nodo della lista
	app = malloc(sizeof(struct Nodo)); 				// allocazione nodo nell'heap
	
	/* leggi il campo dati */
	printf("Inserisci l'intero!\n");
	scanf("%d", &(app -> numero)); 							
	printf("\n");
	
	/* collega il nodo tra la testa e il primo nodo */
	app->next = head->next;								
	head->next = app;  //attenzione: le assegnazioni devono seguire questo ordine						

	printf("Inserimento effettuato!\n\n");
}

/* funzione che inserisce un nodo in coda alla lista */		
void inserisciCoda3(struct Nodo *head) {
	struct Nodo *nuovoNodo; 								// il nuovo nodo della lista
	nuovoNodo = malloc(sizeof(struct Nodo)); 		// allocazione nuovo nodo nell'heap

	/* riempi i campi del nuovo nodo */
	printf("Inserisci l'intero!\n");
	scanf("%d", &(nuovoNodo -> numero)); 							
	printf("\n");
	nuovoNodo->next = NULL;
	
	/* collega il nodo al precedente: devi cercare l'ultimo nodo della lista, che potrebbe
	 * anche essere quello fittizio */
	while(head->next != NULL) 		// l'ultimo nodo ha il campo next vuoto 
		head=head->next;				// scorri di 1

		/* ora head contiene l'indirizzo dell'ultimo nodo della lista */
		head->next = nuovoNodo;							

	printf("Inserimento effettuato!\n\n");
}


/*********************************************************
 ************************ CANCELLAZIONI *******************
 *********************************************************/ 

/* funzione che cancella un nodo dalla testa della lista */		
void cancellaNodo3(struct Nodo *head) {
	struct Nodo *app;											// il nuovo primo nodo della lista
	
	/* lista vuota? */
	if(head->next!=NULL){
		app = head->next; //devo ricordare l'indirizzo del nodo da cancellare per deallocarlo
		head->next=app->next;
		free(app);
		printf("Cancellazione effettuata!\n\n");
	}							
	else
		printf("Niente da cancellare!\n\n");

}

/* funzione che cancella il primo nodo con un certo valore */		
void cancellaValore3(struct Nodo *head, int valore) {
	struct Nodo *butta;	// appoggio  per deallocazione di memoria
	int cancellato=0;    //inizialmente non ho cancellato niente
    
	/* controlla head->next, per vedere se è il nodo cercato: vai avanti fino
	 * a che esiste un tale nodo e non hai trovato il nodo da cancellare */
	while(head->next!=NULL && !cancellato){
		if (head->next->numero==valore){
			/* nodo cercato: devi collegare il precedente al successivo e buttare 
			 * il corrente */
			butta = head->next;
			head->next = butta->next;
			free(butta);
			cancellato = 1;
		}
		else
			head = head->next; 
	}	
    if(!cancellato) printf("%d non e' presente nella lista\n",valore);
}

/*********************************************************
 ************************ LUNGHEZZA **********************
 *********************************************************/ 

/* funzione che calcola il numero di elementi di una lista */
int lunghezza(struct Nodo* head) {
	struct Nodo *nodo = head;		// nodo generico
	int lunghezza = 0;					// valore da calcolare
	
    nodo=head->next; //supero il nodo fittizio
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
    struct Nodo *massimo;
    struct Nodo *nodo;
    nodo = head->next; //supero il nodo fittizio
    
    /*inizio*/
	massimo = nodo;			// inizialmente il massimo è il primo nodo
	nodo = head->next;		// parti dal secondo nodo
	/* vai avanti fino a che ci sono elementi */
	while(nodo!= NULL) {
		if(maggiore(nodo,massimo)) 
			massimo = nodo;
		nodo = nodo->next;
	}
	return massimo;
}	

/*********************************************************
 ************************ MAIN ****************************
 *********************************************************/ 

/* funzione principale */
int main() {
	int risposta = -1;									// valore inserito dall'utente
	struct Nodo *head; 		       					// lista inizialmente vuota
	head = malloc(sizeof(struct Nodo)); 			// creo il primo nodo fittizio
    head->next=NULL;
    
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
		printf("Introduci 0 -> Termina il programma\n");
		scanf("%d%*c", &risposta);

		/* Inserimento in testa */
		if(risposta==1) 
			inserisciNodo3(head);
		/* Inserimento in coda */
		else if(risposta==2) 
			inserisciCoda3(head);
		/* Cancellazione in testa */
		else if(risposta==3) { 
			cancellaNodo3(head);
			printf("\n");
		}
		/* Cancellazione valore */
		else if(risposta==4) {
			int valore;			// valore da cancellare
			printf("Che valore vuoi cancellare?\n");
			scanf("%d%*c", &valore);
			cancellaValore3(head, valore);
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
		/* numero sbagliato? */
		else  if(risposta!=0)
			printf("Questo numero non vuol dire niente. Riproviamo!\n\n");
	}
}	
