/***

Name:			Lotto
Beschreibung:	Programm, in welchem der User Lottozahlen tippen kann. Gespielt wird 6 aus 49. Nach Tippen der 6 Zahlen, werden die "Richtigen"
				gezogen, und die Gewinnquote bestimmt.
Autorinnen:	    Emily Klemt, Carolin Altstaedt
Datum:		    19.11.2023
Version:			1

***/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Deklaration 
short getShortMinMax(char text[], int min, int max);


int main() {

	int getippteLottozahlen[6]; // Array zum Abspeichern der 6 getippten Lottozahlen
	int maxTips = 6; // maximale Tippzahl
	int untereGrenze = 1; // Definition der unteren Grenze des Tipzahlenbereiches
	int obereGrenze = 49; // Definition der oberen Grenze des Tipzahlenbereiches

	// *** //
	printf("Willkommen bei 6 aus 49. Du kannst 6 Zahlen zwischen 1 und 49 tippen. Im Anschluss siehst du, ob und wieviel du gewonnen hast.\n\n\n");
	printf("Bitte tippe nun deine 6 Lottozahlen:\n\n\n\n");
	// *** //

	bool ersterDurchlauf = true;

	for (int i = 0; i < maxTips; i++) {
		 
		printf("Du tippst gerade deine %d. Lottozahl von 6:\n", i + 1);

		// Lottoschein im ersten Durchlauf blanko darstellen, in allen weiteren modifiziert mit Angabe der User-Tips
		if (ersterDurchlauf) {
			//Lottoschein grafisch anzeigen
			printf("Lottoschein:\n\n");
			for (int j = 1; j <= 49; j++) {
				if (j % 7 == 0) {
					printf("%3d\n", j);
				} else {
					printf("%3d", j);
				}
			}
			printf("\n\n");

			// Abfrage eines Lottotips und Abpeichern des Rückgabewerts in tip
			int tip = getShortMinMax("Bitte gib eine Zahl zwischen 1 und 49 ein", untereGrenze, obereGrenze);

			// eingelesene Zahl in Array abspeichern
			getippteLottozahlen[i] = tip;

			// Abschluss des ersten Durchlaufs
			ersterDurchlauf = false;

		} else {
			//Lottoschein mit angekreuzten Zahlen 
			
			printf("Lottoschein:\n\n");
			// Ausgabe Lottoschein mit Formatierung und X-Markierung der getippten Zahlen
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
			printf("\n\n");

			/*
			Abfrage eines Lottotips und Abpeichern des Rückgabewerts, 
			wurde eine Zahl bereits im Array gespeichert,
			wiederholte Abfrage nach einer neuen Zahl
			*/
			int zahlZumEinlesen = 0;
			bool keinNeuerWert = true;
			while (keinNeuerWert) {
				keinNeuerWert = false;
				zahlZumEinlesen = getShortMinMax("Gib einen neuen Tipp ab", untereGrenze, obereGrenze);
				for (int k = 0; k < 6; k++) {
					if (zahlZumEinlesen == getippteLottozahlen[k]) {
						printf("Die Zahl hattest du schonmal getippt!\n");
						k += 6;
						keinNeuerWert = true;
					}
				}
			}

			// eingelesene Zahl in Array abspeichern
			getippteLottozahlen[i] = zahlZumEinlesen;
		}

		// Konsole übersichtlich aufräumen vor jedem neuen Schleifendurchlauf
		system("cls");
	}

	// Konsole vor Ergebnisausgabe aufräumen
	system("cls"); 


	// Ausgabe: fertigen Lottoschein mit X-Markierung der getippten Zahlen ausgeben 
	printf("Lottoschein:\n");
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

	//Ausgabe: Liste aller getippten Zahlen
	printf("\n\nListe der getippten Zahlen: ");
	ersterDurchlauf = true;
	for (int p = 0; p < 6; p++) {
		if (ersterDurchlauf) {
			printf("%d", getippteLottozahlen[p]);
			ersterDurchlauf = false;
		}
		else {
			printf(", %d", getippteLottozahlen[p]);
		}
	}

	/*
	Generierung 6 zufälliger Zahlen zwischen 1 und 49 und Abspeichern in Array,
	Überprüfung ob generierte Zahl bereits in Array gespeichert wurde,
	dann erneute generierung einer zufälligen Zahl
	*/
	int gezogeneZahlen[6]; 
	int maxGezogeneZahlen = 6; 
	int random = 0; 
	ersterDurchlauf = true;
	srand((unsigned int)time(NULL)); // Initialisieren der random-Funktion, Rückgabewert als unsigned int casten, notwendig für srand

	for (int q = 0; q < maxGezogeneZahlen; q++) {
		//bei Generierung der ersten Zahl keine Überprüfung des Arrays notwendig
		if (ersterDurchlauf) {
			random = rand() % 49; //Begrenzung der Zufallszahlen 1 - 49
			ersterDurchlauf = false;
		} else {
			bool keinNeuerWert = true;
			while (keinNeuerWert) {
				keinNeuerWert = false; 
				random = rand() % 49; //Begrenzung der Zufallszahlen 1 - 49
				for (int r = 0; r < 6; r++) {
					if (random == gezogeneZahlen[r]) {
						keinNeuerWert = true; 
					}
				}
			}
		}
		gezogeneZahlen[q] = random; 
	}
	//Ausgabe: Liste aller gezogenen Zahlen
	printf("\nListe der gezogenen Zahlen: ");
	ersterDurchlauf = true; 
	for (int s = 0; s < 6; s++) {
		if (ersterDurchlauf) {
			printf("%d", gezogeneZahlen[s]);
			ersterDurchlauf = false; 
		}
		else {
			printf(", %d", gezogeneZahlen[s]);
		}
	}

	//Bestimmung der richtig getippten Zahlen durch Vergleich der Arrays Ziehung und Tipps
	int anzahlRichtige = 0;
	for (int t = 0; t < 6; t++) {
		for (int u = 0; u < 6; u++) {
			if (gezogeneZahlen[t] == getippteLottozahlen[u]) {
				anzahlRichtige++; 
				u += 6; 
			}
		}
	} 
	//Ausgabe: Zahl der richtigen Tipps
	printf("\n\nAnzahl der richtig getippten: %d\n", anzahlRichtige); 
	
	//Ausgabe: Angabe der Gewinnquote
	if (anzahlRichtige == 1)
		printf("Lottospielen ist doof, man gewinnt mit einer Richtigen leider nichts!\n");
	else if (anzahlRichtige == 2)
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


//Funktionsrumpf
short getShortMinMax(char text[], int min, int max) {
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
