#include <stdio.h>
#include <stdbool.h>

/*
short getShort(			//[out] user input 
	char text[])		//[in] question for user input
{
	short value;		//user input
	int finished = false;	//flag for correct user input 
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
		else finished = true;

		//clear input stream
		while (ch != '\n') scanf("%c", &ch); 
	// repeat if not finished
	} while (!finished); 

	//return user input
	return value; 

}
*/

short getShortMinMax(			//[out] user input 
	char text[],
	int min,
	int max)		//[in] question for user input
{
	short value;		//user input
	bool finished = false;	//flag for correct user input 
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
		else if (value < min || value > max) printf("Zahl muss zwischen 1 und 49 liegen.\n");
		else finished = true;

		//clear input stream
		while (ch != '\n') scanf("%c", &ch); 
	// repeat if not finished
	} while (!finished); 

	//return user input
	return value; 

}


int main() {

	int getippteLottozahlen[6];
	int maxTips = 6;
	int untereGrenze = 1;
	int obereGrenze = 49;
	

	printf("Bitte tippe 6 Lottozahlen:\n");

	for(int i = 0; i < maxTips-1; i++) {
		bool ersterDurchlauf = true;

		printf("Du tippst gerade deine %d. Lottozahl von 6:", i+1);

		if(ersterDurchlauf) {
			//Lottoschein grafisch anzeigen
			for(i = 1; i <= 49; i++) {
				if (i % 7 == 0) {
					printf("%d\n", i);
				} else {
					printf("%d", i);
				}
			}
			//

			int tip = getShortMinMax("Bitte gib eine Zahl zwischen 1 und 49 ein", untereGrenze, obereGrenze);

			getippteLottozahlen[i] = tip;






			ersterDurchlauf = false;
		}


		
	}

      printf("%d ", getippteLottozahlen[0]);



	


	// neue Funktion um Lottozahlen abzufragen 

		//Funktion nutzen um Lottozahlen abzufragen 
		// in Array speichern 

		// weiteren Array machen mit zuf�lligen Lottozahlen 
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