#define _CRT_SECURE_NO_WARNINGS

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

	bool ersterDurchlauf = true; //erster Durchlauf der Lottozahlen

	for (int i = 0; i < maxTips; i++) {


		printf("Du tippst gerade deine %d. Lottozahl von 6:\n", i + 1);

		if (ersterDurchlauf) {
			//Lottoschein grafisch anzeigen
			printf("Lottoschein;\n");
			for (int j = 1; j <= 49; j++) {
				if (j % 7 == 0) {
					printf("%3d\n", j);
				}
				else {
					printf("%3d", j);
				}
			}
			//

			int tip = getShortMinMax("Bitte gib eine Zahl zwischen 1 und 49 ein", untereGrenze, obereGrenze);
			printf("%d\n", tip);
			printf("%d\n", i);
			getippteLottozahlen[i] = tip;
			printf("%d\n", getippteLottozahlen[0]);

			ersterDurchlauf = false;
		}
		else {
			//Lottoschein mit angekreuzten Zahlen 
			
			printf("Lottoschein;\n");
			for (int l = 1; l <= 49; l++) {
				bool zahlMitX = false;
				for (int m = 0; m < 6; m++) {
					if (l == getippteLottozahlen[m]) {
						zahlMitX = true;
						m += 7;
					}
				}
				printf("%3d", l);
				if (zahlMitX) printf("x");
				if (l % 7 == 0) printf("\n");
			}
			int zahlZumEinlesen = 0;
			bool keinNeuerWert = true;
			while (keinNeuerWert) {
				keinNeuerWert = false;
				zahlZumEinlesen = getShortMinMax("Gib einen weiteren Tipp ab", untereGrenze, obereGrenze);
				for (int k = 0; k < 6; k++) {
					if (zahlZumEinlesen == getippteLottozahlen[k]) {
						k += 6;
						keinNeuerWert = true;
					}
				}

			}
			printf("%d\n", zahlZumEinlesen);
			printf("%d\n", i);
			getippteLottozahlen[i] = zahlZumEinlesen;
			printf("%d\n", getippteLottozahlen[i]);
		}
	}
	// fertigen Lottoschein ausgeben 
	printf("Lottoschein;\n");
	for (int n = 1; n <= 49; n++) {
		bool zahlMitX = false;
		for (int o = 0; o < 6; o++) {
			if (n == getippteLottozahlen[o]) {
				zahlMitX = true;
				o += 7;
			}
		}
		printf("%3d", n);
		if (zahlMitX) printf("x");
		if (n % 7 == 0) printf("\n");
	}
	for (int p = 0; p < 6; p++) {
		printf("%d,", getippteLottozahlen[p]);
	}

	


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

	return 0; 
}
