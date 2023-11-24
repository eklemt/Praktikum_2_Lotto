#define _CRT_SECURE_NO_WARNINGS

/***

Name:			Lotto
Beschreibung:	Programm, in welchem der User Lottozahlen tippen kann. Gespielt wird 6 aus 49. Nach Tippen der 6 Zahlen, werden die "Richtigen"
				gezogen, und die Gewinnquote bestimmt.
Autorinnen:	    Emily Klemt, Carolin Altstaedt
Datum:		    19.11.2023
Version:		1

***/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Deklaration 
short einlesenEinerZahl(char text[], short min, short max);
void gibEinenLottoscheinAus(short array[]);
bool istInArray(short zahl, short array[]);

int main() {

	short getippteLottozahlen[6]; // Array zum Abspeichern der 6 getippten Lottozahlen
	short maxTips = 6; // maximale Tippzahl
	short untereGrenze = 1; // Definition der unteren Grenze des Tipzahlenbereiches
	short obereGrenze = 49; // Definition der oberen Grenze des Tipzahlenbereiches

	// *** //
	printf("Willkommen bei 6 aus 49. Du kannst 6 Zahlen zwischen 1 und 49 tippen. Im Anschluss siehst du, ob und wieviel du gewonnen hast.\n\n");
	printf("Bitte tippe nun deine 6 Lottozahlen:\n\n");
	// *** //

	bool ersterDurchlauf = true; //erster Durchlauf der Lottozahlen

	for (int i = 0; i < maxTips; i++) {
		printf("Du tippst gerade deine %d. Lottozahl von 6:\n", i + 1);

		if (ersterDurchlauf) {
			//Lottoschein grafisch anzeigen
			gibEinenLottoscheinAus(getippteLottozahlen);
			printf("\n");

			// Abfrage eines Lottotips und Abpeichern des Rückgabewerts in tip
			short tip = einlesenEinerZahl("Bitte gib eine Zahl zwischen 1 und 49 ein", untereGrenze, obereGrenze);

			// eingelesene Zahl in Array abspeichern
			getippteLottozahlen[i] = tip;

			// Abschluss des ersten Durchlaufs
			ersterDurchlauf = false;
		}
		else {
			//Lottoschein mit angekreuzten Zahlen grafisch anzeigen 
			gibEinenLottoscheinAus(getippteLottozahlen);
			printf("\n\n");

			/*
			Abfrage eines Lottotips und Abpeichern des Rückgabewerts,
			wurde eine Zahl bereits im Array gespeichert,
			wiederholte Abfrage nach einer neuen Zahl
			*/

			short tip = 0;
			bool gefunden = true;
			while (gefunden) {
				gefunden = false;
				tip = einlesenEinerZahl("Gib einen weiteren Tipp ab", untereGrenze, obereGrenze);
				gefunden = istInArray(tip, getippteLottozahlen);
				if (gefunden) {
					printf("Die Zahl hattest du schonmal getippt!");
				}
			}
			// eingelesene Zahl in Array abspeichern
			getippteLottozahlen[i] = tip;
		}

		// Konsole übersichtlich aufräumen vor jedem neuen Schleifendurchlauf
		system("cls");

	}

	// Konsole vor Ergebnisausgabe aufräumen
	system("cls");

	// Ausgabe: fertigen Lottoschein mit X-Markierung der getippten Zahlen ausgeben 
	gibEinenLottoscheinAus(getippteLottozahlen);

	//Ausgabe: Liste aller getippten Zahlen
	printf("\n\nListe der eingegebenen Zahlen: ");
	ersterDurchlauf = true;
	for (int p = 0; p < 6; p++) {
		if (ersterDurchlauf) {
			printf("%d", getippteLottozahlen[p]);
			ersterDurchlauf = false;
		}
		else {
			printf(",%d", getippteLottozahlen[p]);
		}
	}

	/*
	Generierung 6 zufälliger Zahlen zwischen 1 und 49 und Abspeichern in Array,
	Überprüfung ob generierte Zahl bereits in Array gespeichert wurde,
	dann erneute generierung einer zufälligen Zahl
	*/

	short gezogeneZahlen[6]; // Array für Zahlen, die zufällig als Gewinnzahlen gezogen werden 
	ersterDurchlauf = true;
	short zufälligeZahl = 0; // Zufällig gezogene Zahl 
	srand((unsigned int)time(NULL)); // Initialisieren der random Funktion 

	for (int q = 0; q < maxTips; q++) {
		bool keinNeuerWert = true;
		while (keinNeuerWert) {
			keinNeuerWert = false;
			zufälligeZahl = rand() % 50 +1; //Begrenzung bis 49
			keinNeuerWert = istInArray(zufälligeZahl, gezogeneZahlen);
		}
		gezogeneZahlen[q] = zufälligeZahl;
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
			printf(",%d", gezogeneZahlen[s]);
		}
	}

	//Bestimmung der richtig getippten Zahlen durch Vergleich der Arrays Ziehung und Tipps
	short zuCheckendeZahl;
	short anzahlRichtige = 0;
	for (int t = 0; t < 6; t++) {
		bool inArray = false;
		zuCheckendeZahl = gezogeneZahlen[t];
		inArray = istInArray(zuCheckendeZahl, getippteLottozahlen);
		if (inArray) {
			anzahlRichtige++;
		}
	}
	//Ausgabe: Zahl der richtigen Tipps
	printf("\n\nAnzahl der richtig getippten: %d\n", anzahlRichtige);

	//Ausgabe: Angabe der Gewinnquote
	if (anzahlRichtige == 2)
		printf("2 Richtige getippt. Du hast 5 Euro gewonnen.\n");
	else if (anzahlRichtige == 1)
		printf("Lottospielen ist doof, man gewinnt mit einem richtigen leider nichts!\n");
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


short einlesenEinerZahl(
	char text[],
	int min,
	int max)
{
	short eingelesenerWert;		//eingegebene Zahl des Benutzers
	bool fertig = false;	// Variable, die anzeigt, ob die Eingabe den Anforderungen einer Lottozahl entspricht
	char ch;			//möglicher Buchstabe nach der eingegebenen Zahl
	int Rückgabewert;			//Rückgabewert von scanf

	do {
		//Einlesen der Zahl 
		printf("%s: ", text);
		ch = '\0';
		Rückgabewert = scanf("%hd%c", &eingelesenerWert, &ch);

		// Überprüfen, ob die Zahl den Anforderungen entspricht
		if (Rückgabewert != 2) printf("Das war keine korrekte Zahl!\n");
		else if (ch != '\n') printf("Unerwartete Zeichen hinter der Zahl!\n");
		else if (eingelesenerWert < min || eingelesenerWert > max) printf("Zahl muss zwischen 1 und 49 liegen.\n");
		else fertig = true;

		// Input stream leeren 
		
		while (ch != '\n') {
			char checkChar = scanf("%c", &ch);
		}
		// wiederholen, wenn es nicht beendet ist 
	} while (!fertig);

	// Rückgabe der eingelesenen Zahl 
	return eingelesenerWert;

}

void gibEinenLottoscheinAus( //Funktion zum Ausgeben eines Lottoscheins und markieren von bereits getippten Zahlen mit einem x 
	short array[])
{
	printf("Lottoschein:\n");
	for (int l = 1; l <= 49; l++) {
		bool zahlMitX = false;
		for (int m = 0; m < 6; m++) {
			if (l == array[m]) {
				zahlMitX = true;
				m += 7;
			}
		}
		// Ausgabe: Lottozahlen auf dem Schein 
		printf("%3d", l);
		if (zahlMitX) printf("x");
		else printf(" ");
		if (l % 7 == 0) printf("\n");
	}
}

bool istInArray(short zahl, short array[]) { //Funktion zum Überprüfen ob eine Zahl Bestandteil eines Arrays ist 
	bool gefunden = false;
	for (int k = 0; (k < 6) && !gefunden; k++) {
		if (zahl == array[k]) {
			gefunden = true;
		}
	}
	return gefunden;
}
