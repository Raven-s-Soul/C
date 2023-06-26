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

// passaggio della struct per riferimento
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

//oppure funzione che restituisce una struct
SEGM leggiDati2() {
	//definisco la struct in cui acqusire i dati
	SEGM s;
	printf("Dammi la coordinata x dell'estremo sinistro: ");
	scanf("%f", &(s.es.x));
	printf("Dammi la coordinata y dell'estremo sinistro: ");
	scanf("%f", &(s.es.y));
	do {
		printf("Dammi la lunghezza del segmento: ");
		scanf("%f", &(s.lun));
		if(s.lun<=0)   printf("Le lunghezze sono positive!\n");
	}
	while(s.lun<=0);
	return s;
}


void inserisciCoda(NODO* head) {

	//preparo il nuovo nodo da inserire
	NODO* nuovo = malloc(sizeof(NODO));

	//con leggidati
	//leggiDati(&nuovo->s);

	//con leggidati2
	nuovo->s=leggiDati2();

	nuovo->next = NULL;

	/* mi porto sull'ultimo nodo */
	while(head->next!=NULL)
		head= head->next;

	/* collego l'ultimo nodo al nuovo */
	head->next = nuovo;

	printf("Inserimento effettuato\n\n");
}

/**********************************************
 ******* CANCELLAZIONE ************************
 **********************************************/

void cancella12(NODO* head) {
	NODO *butta; //per deallocare il nodo da cancellare
	/* lista vuota? */
	if(head->next == NULL)
		printf("Lista vuota, niente da cancellare\n\n");
	/* lista non vuota */
	else {
		while(head->next!=NULL && head->next->s.lun!=12)
			head=head->next;
		//esco dal while, o con head->next che e' NULL
		// o perche' il nodo successivo a head contiene un segmento lungo 12, quindi lo devo cancellare
		/* cancellazione in testa */
		if (head->next==NULL) //ho finito senza cancellare nulla
			printf("Non esistono segmenti di lunghezza 12 nella lista\n\n");
		else{
			butta=head->next;
			head->next=head->next->next;
			free(butta);
			printf("Cancellazione effettuata\n\n");
		}
	}
}

/**************************************/
/*********** VISUALIZZAZIONE **********/
/**************************************/

void visualizzaSegmento(SEGM* s) {
	printf("Segmento con estremi (%.2f,%.2f) e (%.2f,%.2f) e lunghezza %.2f\n",
			s->es.x, s->es.y, s->es.x + s->lun, s->es.y, s->lun);
}

void visualizzaLista(NODO* head) {
	head=head->next; //salto il nodo fittizio
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
	/* inizializza la lista con il nodo fittizio */
	NODO* head = malloc(sizeof(NODO));
	head->next = NULL;

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
			inserisciCoda(head);
		else if(risposta==2)
			cancella12(head);
		else if(risposta==3)
			visualizzaLista(head);
		else if(risposta==0)
			printf("Finito!\n\n");
		else printf("Selezione non valida!\n\n");
	}
}