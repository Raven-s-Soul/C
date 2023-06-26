#include <stdio.h>
#include <stdlib.h>

/*****************************/
/********* STRUTTURE *********/
/*****************************/

typedef struct Punto {
	float x;
	float y;
} PUNTO;

typedef struct Segmento {
	PUNTO es;
	float lun;
} SEGM;

typedef struct Nodo {
	SEGM s;
	struct Nodo* next;
} NODO;

/**********************************************
 **************** INSERIMENTO *****************
 **********************************************/

void leggiDati(SEGM* s) {
	printf("Dammi la coordinata x dell'estremo sinistro: ");
	scanf("%f", &(s->es.x));
	printf("Dammi la coordinata y dell'estremo sinistro: ");
	scanf("%f", &(s->es.y));
	do {
		printf("Dammi la lunghezza del segmento: ");
		scanf("%f", &(s->lun));
		if(s->lun<=0)
			printf("Le lunghezze sono positive!\n");
	}
	while(s->lun<=0);	
}

NODO* inserisciCoda(NODO* head) {
	NODO* nuovo = malloc(sizeof(NODO));
	leggiDati(&nuovo->s);
	nuovo->next = NULL;
	/* inserimento in testa */
	if(head==NULL)
		head=nuovo;
	/* inserimento non in testa */
	else {
		NODO* nodo = head;
	
		/* portati sull'ultimo nodo */
		while(nodo->next!=NULL)
			nodo= nodo->next;
			
		/* collega l'ultimo nodo al nuovo */
		nodo->next = nuovo;	
	}	
	printf("Inserimento effettuato\n\n");
	return head;
}

/**********************************************
 ******* CANCELLAZIONE ************************
 **********************************************/

NODO* cancella12(NODO* head) {
	/* lista vuota? */
	if(head==NULL) 
		printf("Lista vuota, niente da cancellare\n\n");
	/* lista non vuota */
	else {
		/* cancellazione in testa */
		if(head->s.lun==12) {
			NODO* dealloca = head;
			head = head->next;
			free(dealloca);
			printf("Cancellazione effettuata\n\n");
		}
		/* cancellazione non in testa */
		else {
			int trovato = 0;
			NODO* nodo = head;
			/* vai a cercare un segmento pari a 12, se c'è */
			while(nodo->next!=NULL && !trovato)
				if(nodo->next->s.lun==12) 
					trovato = 1;
				else
					nodo=nodo->next;
				
			/* nodo trovato */
			if(trovato) {
				NODO* dealloca = nodo->next;
				nodo->next = nodo->next->next;
				free(dealloca);
				printf("Cancellazione effettuata\n\n");
			}
			/* nodo non trovato */
			else {
				printf("Non esistono segmenti di lunghezza 12\n\n");
			}
		}
	}
	return head;
}

/**************************************/
/*********** VISUALIZZAZIONE **********/
/**************************************/

void visualizzaSegmento(SEGM* s) {
	printf("Segmento con estremi (%.2f,%.2f) e (%.2f,%.2f) e lunghezza %.2f\n",
			s->es.x, s->es.y, s->es.x + s->lun, s->es.y, s->lun);
}

void visualizzaLista(NODO* head) {
	/* lista vuota? */
	if(head==NULL)
		printf("Lista vuota!\n\n");
	else {
		/* lista non vuota */
		printf("*****************\n");
		while(head!=NULL) {
			visualizzaSegmento(&head->s);
			head=head->next;
		}
		printf("*****************\n\n");
	} 
}

/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main() {
	/* inizializza la lista */
	NODO* head = NULL;	

	int risposta = -1;			// per interazione con utente
	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserimento\n");
		printf("2 -> Cancellazione\n");
		printf("3 -> Visualizzazione\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);

		/* gestisci le operazioni dell'utente */
		if(risposta==1)
			head = inserisciCoda(head);
		else if(risposta==2)
			head = cancella12(head);
		else if(risposta==3)
			visualizzaLista(head);
		else if(risposta==0)
			printf("Finito!\n\n");
		else printf("Selezione non valida!\n\n");
	}
}