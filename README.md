# Praktikum 2: Ziehung der Lottozahlen
In diesem Praktikum soll ein(e) Benutzer*in Lottozahlen tippen können. Danach werden zufällig die
Lottozahlen gezogen, „Anzahl der Richtigen“ bestimmt und die Gewinnquote ausgegeben. Wir
spielen 6 aus 49 (ohne Zusatzzahl).<br><br>


## Schritt 1: Projekt anlegen & Funktion getShort() testen
Legen Sie ein neues Projekt mit dem Namen „Lotto“ an. Implementieren und testen Sie folgende
Funktion zur sicheren Abfrage einer ganzen Zahl vom Typ short.

## Schritt 2: Funktion mit min/max-Werten
Schreiben Sie eine weitere Funktion mit Namen getShortMinMax und nutzen Sie getShort als
Startpunkt. Die Funktion getShortMinMax soll um zwei weitere Funktionsparameter Min und Max
(ähnlich dem Beispiel getInt aus der Vorlesung) ergänzt werden. Im Funktionsrumpf soll geprüft
werden, ob die Benutzereingabe zwischen Min und Max liegt. Falls nein, soll die Benutzereingabe
wiederholt werden.

## Schritt 3: Lottozahlen tippen
Fragen Sie vom Benutzer*in einzeln die 6 Lottozahlen ab, welche getippt werden sollen. Nutzen Sie
hierfür die Funktion aus Schritt 2. Speichern Sie den Tipp in einem Vektor (Array). Achten Sie auf eine
gute Benutzerführung, so dass ihr Programm selbsterklärend ist.

## Schritt 4: Lottozahlen ziehen
Machen Sie sich mit den Funktionen rand() und srand() aus der stdlib vertraut. Nutzen Sie hierfür
eine Sprachreferenz1
. Mit Hilfe dieser Funktion sollen Sie nun zufällige Lottozahlen ziehen und diese
in einem weiteren Vektor speichern. Achten Sie darauf, dass Sie am Ende der Ziehung sechs
unterschiedliche Zahlen bestimmt haben.
Geben Sie die gezogenen Lottozahlen für den/die Benutzer*in aus!

## Schritt 5: Anzahl der Richtige bestimmen
Bestimmen Sie die „Anzahl der Richtigen“, indem Sie die getippten Zahlen mit den Gewinnzahlen
vergleichen.
Geben Sie die Anzahl der Richtigen für den/die Benutzer*in aus!

## Schritt 6: Gewinnquote bestimmen
Bestimmen Sie die Gewinnquote anhand der folgenden Tabelle und geben Sie den Gewinn aus.
| Richtige | Gewinnsumme |
|----------|-------------|
| 2        | 5 Eur       |
| 3        | 50          |
| 4        | 1.000       |
| 5        | 50.000      |
| 6        | 1.000.000   |

## Schritt 7: Quellcode gestalten
Gehen Sie bei der Gestaltung des Quellcodes wie beim letzten Praktikum vor. Des Weiteren:
• Verwenden Sie keine globalen Variablen
• Halten Sie die übliche Reihenfolge ein: Makros (wenn vorhanden), Include-Befehle ,
Funktionsdeklarationen, Hauptprogramm, Funktionsdefinitionen
• Fügen Sie zur besseren Gliederung Leerzeilen und ggf. Linien ein


## Zusatzaufgabe 1 (optional): Tipp überprüfen
Überprüfen Sie die Benutzereingabe aus Schritt 3 auf doppelte Eingaben. Wiederholen Sie die
Abfrage, falls die eingegebene Zahl schon getippt worden ist.


## Zusatzaufgabe 2 (optional): Lottozettel ausgeben
Verändern Sie die Benutzereingabe aus Schritt 3, wie folgt:
Geben Sie den Lottoschein aus, welchen Sie schon in der Vorlesung programmiert haben. Fragen Sie
vom Benutzer*in einzeln die 6 Lottozahlen ab, welche getippt werden sollen. Aktualisieren Sie nach
jeder getippten Zahl den Lottoschein und markieren Sie die getippten Zahlen z.B. mit einem „x“
hinter der Zahl (siehe Screenshot). Überlegen Sie sich eigenständig, für was Sie eine Funktion nutzen
möchten! 