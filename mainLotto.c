#include <stdio.h>

short getShort(			//[out] user input 
	char text[])		//[in] question for user input
{
	short value;		//user input
	int finished = 0;	//flag for correct user input 
	char ch;			//character behind number 
	int retVal;			//return value of scanf 

	do {
		//get user input 
		printf("%s: ", text); 
		ch = '\0'; 
		retVal = scanf("%hd%c", &value, &ch); 

		// check for valid user input 
		if (retVal != 2) printf("Das war keine korrekte Zahl!\n");
		else if (ch != '\n') printf("Unerwartete Zeichen hinter der Zahl!\n");
		else finished = 1; 

		//clear input stream
		while (ch != '\n') scanf("%c", &ch); 
	// repeat if not finished
	} while (!finished); 

	//return user input
	return value; 

}
int main() {
	// neue Funktion um Lottozahlen abzufragen 

		//Funktion nutzen um Lottozahlen abzufragen 
		// in Array speichern 

		// weiteren Array machen mit zufälligen Lottozahlen 
		// darauf achten, dass keine Lottozahlen doppelt gespeichert werden 
		// einfaches if-else 

		//richtige Zahlen mit Gewinnquote bestimmen 
		// Arrays mit einander vergleichen 
	int anzahlRichtige = 0;

	//Gewinnquote bestimmen 
	if (anzahlRichtige == 2)
		printf("2 Richtige getippt. Du hast 5 Euro gewonnen.\n");
	else if (anzahlRichtige == 3)
		printf("3 Richtige getippt. Du hast 50 Euro gewonnen\n");
	else if (anzahlRichtige == 4)
		printf("4 Richtige getippt. Du hast 1.000 Euro gewonnen\n");
	else if (anzahlRichtige == 5)
		printf("5 Richtige getippt. Du hast 50.000 Euro gewonnen\n");
	else if (anzahlRichtige == 6)
		printf("6 Richtige getippt. Du hast 1 Million Euro im Lotto gewonnen\n");
	else
		printf("Du hast leider nichts gewonnen.\n");

}