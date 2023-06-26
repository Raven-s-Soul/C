#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* strutture */
typedef struct Computer {
	char modello[20];
	int codice;
	int IP[12];
} COMP;

typedef struct Nodo {
	COMP computer;
	struct Nodo* next;
} NODO;

/* visualizzazione di un computer */
void visualizzaComputer(COMP* c) {
	printf("Modello: %s, codice %d, ip: ", c->modello, c->codice);
	for(int i=0; i<12; i++) {
		printf("%d", c->IP[i]);
		if(i==2 || i==5 || i==8)
			printf(".");
	}
	printf("\n\n");
}

/* visualizzazione di una lista */
void visualizzaLista(NODO* head) {
	/* lista vuota */
	if(head==NULL)
		printf("Nessun computer da visualizzare!\n\n");
	/* lista non vuota */
	else {
		printf("Ecco la lista*********\n\n");
		while(head!=NULL) {
			visualizzaComputer(&(head->computer));
			head=head->next;
		}
		printf("Fine lista*********\n\n");
	}
}

/* verifica di un computer con dato codice */
int esisteComputer(NODO* head, int cod) {
	int esiste = 0;			// risultato
	while(head!=NULL && !esiste) 
		/* computer corrente e' quello buono? */
		if(head->computer.codice == cod)
			esiste = 1;
		else 
			head=head->next;
	return esiste;
}

/* cancellazione in testa */
void cancellaComputer(NODO** puntaHead) {
	/* lista vuota? */
	if(*puntaHead==NULL)
		printf("Lista vuota\n\n");
	/* lista non vuota */
	else {
		NODO* dealloca = *puntaHead;
		*puntaHead = (*puntaHead)->next;
		free(dealloca);
		printf("Cancellazione effettuata\n\n");
	}
}

/* inserimento dati computer */
void inserisciDati(NODO* head, COMP* c) {
	/* leggi il modello */
	printf("Dammi il modello: ");
	fgets(c->modello,20, stdin);
	c->modello[strlen(c->modello)-1] = '\0';
	
	/* leggi IP */
	for(int i=0; i<12; i++) {
		printf("Dammi la cifra numero %d dell'IP: ", i+1);
		scanf("%d", &(c->IP[i]));
		if(c->IP[i]<0 || c->IP[i]>9) {
			printf("Devi darmi una singola cifra!\n");
			i--;
		}
	}
	
	/* trova il codice */
	int trovato = 0;
	int cod = 1;			// codice da assegnare
	/* ripetutamente controlla se il codice attuale e' gia' 
	 * assegnato, se sì passa al prossimo codice, altrimenti fermati */
	while(!trovato) 
		/* verifica se cod sta nella lista */
		if(esisteComputer(head,cod))
			cod++;
		else 
			trovato = 1;
	c->codice = cod;
}
	
/* inserimento in coda */
NODO* inserisciCoda(NODO* head) {
	NODO* nuovo = malloc(sizeof(NODO));
	inserisciDati(head, &(nuovo->computer));
	nuovo->next = NULL;
	
	/* lista vuota */
	if(head==NULL)
		head=nuovo;
	/* lista non vuota */
	else {
		NODO* corrente = head;
		while(corrente->next!=NULL)
			corrente = corrente->next;
		corrente->next=nuovo;
	}
	printf("Inserimento effettuato!\n\n");
	return head;
}

/* funzione principale */
int main() {
	int scelta=-1;				// per interazione con utente
	/* creazione lista */
	NODO* head = NULL;
	
	/* ciclo di interazione */
	while(scelta!=0) {
		printf("Che operazione vuoi svolgere?\n");
		printf("Introduci 0 per terminare\n");
		printf("Introduci 1 per visualizzare la lista\n");
		printf("Introduci 2 per cercare un computer nella lista\n");
		printf("Introduci 3 per cancellare il primo computer dalla lista\n");
		printf("Introduci 4 per inserire un computer nella lista\n");
		
		scanf("%d%*c", &scelta);
		if(scelta==1)
			visualizzaLista(head);
		if(scelta==2) {
			int cod;
			printf("Dammi il codice del computer da cercare\n");
			scanf("%d", &cod);
			if(esisteComputer(head,cod))
				printf("Un computer con quel codice e' nella lista\n\n");
			else
				printf("Nessun computer della lista ha quel codice\n\n");
		}
		if(scelta==3)
			cancellaComputer(&head);
		if(scelta==4)
			head = inserisciCoda(head);
	}
}
