#include <stdio.h>
#include <string.h>

void numeriLunghiNascosti(char *str);
void testNumeriLunghiNascosti();

int main(){
	char str[50];
	printf("Inserisci una stringa: ");
	fgets(str,50,stdin);
	str[strlen(str)-1] ='\0';
	numeriLunghiNascosti(str);
	printf("Stringa modifica: %s\n",str );
	testNumeriLunghiNascosti();

}

// ***** MAIN +2

void numeriLunghiNascosti(char *str){
	int counterNumbers ;
	int j;
	for(int i = 0 ; str[i]!= '\0'; i++){
		if((str[i]>= '0' && str[i]<= '9' )&&(str[i+1]>= '0' && str[i+1]<= '9' )&&(str[i+2]>= '0' && str[i+2]<= '9' )){
			counterNumbers =0;	// ****** INUTILIZZATA....
			j = i+1 ;			// ****** ANCHE DA I+3... 
			while((str[j]!= '\0') && (str[j]>= '0' && str[j]<= '9') ){
				j++;
			}
			//printf("delta %d\n",j-i -2);
			for(int k = i ; str[k] != '\0'; k++){
				str[k] = str[k+ j-i-2]; 
			}
			str[i]= '-';
			str[i+1]= '-';
		}
	}
}

// ****** funzione OK +7

void testNumeriLunghiNascosti(){
	//test generico esplicitato dalla traccia
	char stringa1[] = "12345x67y890ab7c";
	numeriLunghiNascosti(stringa1);
	printf("Test numeriLunghiNascosti(\"12345x67y890ab7c\"): Atteso =\"--x67y--ab7c\", Calcolato = \"%s\" \n",stringa1);
	//stringa vuota
	char stringa2[] = "";
	numeriLunghiNascosti(stringa2);
	printf("Test numeriLunghiNascosti(\"\"): Atteso =\"\", Calcolato = \"%s\" \n",stringa2);
	//meno di 3 caratteri numerici
	char stringa3[] = "12a";
	numeriLunghiNascosti(stringa3);
	printf("Test numeriLunghiNascosti(\"12a\"): Atteso =\"12a\", Calcolato = \"%s\" \n",stringa3);
	// 3 caratteri numerici
	char stringa4[] = "123";
	numeriLunghiNascosti(stringa4);
	printf("Test numeriLunghiNascosti(\"123\"): Atteso =\"--\", Calcolato = \"%s\" \n",stringa4);
	//numerici all inizio(>3) e fine(<3), con lettere nel centro
	char stringa5[] = "12345acb12";
	numeriLunghiNascosti(stringa5);
	printf("Test numeriLunghiNascosti(\"12345acb12\"): Atteso =\"--acb12\", Calcolato = \"%s\" \n",stringa5);
	//numerici alla fine(>3)
	char stringa6[] = "abc123123123";
	numeriLunghiNascosti(stringa6);
	printf("Test numeriLunghiNascosti(\"abc123123123\"): Atteso =\"abc--\", Calcolato = \"%s\" \n",stringa6);
}

// ***** TEST +3