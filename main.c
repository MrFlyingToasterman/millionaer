#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int euronen = 0; //Geldzähler

int main(int argc, char** argv) {
    
    //Variablen
    char rant;  //Richtige Antwort
    char eingabe; //Antwort
    int hauptschleife = 0; //Boolischer wert für hauptschleife
    int prufung = 0; //Boolischer Wert für Prüfungsschleife
    int rechner[10]; //Array Speicher für schon gezogene Zahlen
    int zufall = 0; //Zufallszahl
    int gewcheck = 0; //Zähler für fehlanläufe bei der Prüfungsschleife
    
    //Rechner zählt mit was bereits zufällig gezogen wurde aber erst sezten wir alle seine Werte auf 256
    for (int i = 0; i < 10; i++) {
        rechner[i] = 256;
    }

    do { //Hauptschleife
        
        
        do { //Prüfungsschleife
            
             //Bedingungen für Prüfung auf ausgang setzen
            prufung = 1;
            gewcheck = 0;
            
            //Zufallmethode aufrufen und werte übergeben
            zufall=zufallszahl(10); //Stelle zufallsanzahl auf 10
    
            //Prüfe ob zahl bereits gezogen wurde
            for (int i = 0; i < 10; i++) {
                if (rechner[i] == zufall) {
                    prufung = 0; //Falls Zahl schon gezogen wurde 'würfel' nochmal
                }
            }
            
             for (int i = 0; i < 10; i++) {
                if (rechner[i] == i) {
                    gewcheck++;
                }
            }
            
            if (gewcheck == 10) { //Prüfe Status
                    gewonnen();  //Rufe Methode gewonnen() auf
                    return 0;
            }
            
        }while(prufung == 0);
    
    //zufall verwenden um Frage zu wählen
    switch(zufall)
    {
        case 0: 
            printf("Wann war der berliner Mauerfall?\nA: 1945\tB: 1989\nC: 1988\tD: 1931\n\n");
            rant = 'B';
            rechner[0] = 0;
            break;
         case 1: 
            printf("Wer hat Copy & Paste erfunden (CTRL + C & CTRL + V)?\nA: Bill Gates\tB: Stefan Arbeit\nC: R. Stallman\tD: Dennis Ritchie\n\n");
            rant = 'D';
            rechner[1] = 1;
            break;
        case 2: 
            printf("Wer hat C erfunden?\nA: Isac Newton & sein Kaktus\tB: William Henry Gates\nC: Richard Stallman & Sohn\tD: Dennis Ritchie & Ken Thompson\n\n");
            rant = 'D';
            rechner[2] = 2;
            break;
        case 3: 
            printf("Wer hat den Linuxkernel geschrieben?\nA: Linus Torwalds\tB: Darius Musiolik\nC: Richard Stallman\tD: Dennis Ritchie\n\n");
            rant = 'A';
            rechner[3] = 3;
            break;
        case 4: 
            printf("Wer ist der Begründer der freien Software Bewegung GNU?\nA: Linus Torwalds\tB: Bono\nC: Dennis Hüttenmeister\tD: Richard Stallman\n\n");
            rant = 'D';
            rechner[4] = 4;
            break;
        case 5: 
            printf("Was ist Kismet?\nA: Eine Zigarettenmarke\tB: Ein Festplattenwerkzeug\nC: Ein WiFi Cracker\tD: Eine Microfon Marke\n\n");
            rant = 'C';
            rechner[5] = 5;
            break;
         case 6: 
            printf("Welches Betribssystem ist das Beste?\nA: Linux\tB: Linux\nC: Linux\tD: Linux\n\n");
            rant = 'X';
            rechner[6] = 6;
            break;
        case 7: 
            printf("Was versteht man unter einer JVM?\nA: Justiz Vollzugs Maschine\tB: Ja vielleicht mal sehen\nC: Java Virtual Mashine      \tD: Ja viel mehr\n\n");
            rant = 'C';
            rechner[7] = 7;
            break;
        case 8: 
            printf("Wann war 9/11?\nA: Im roten Oktober\tB: Am 11. 9\nC: Am 9. 11\tD: irgendwann 2002\n\n");
            rant = 'B';
            rechner[8] = 8;
            break;
        case 9: 
            printf("Nennen Sie das unseriöste aus folgenen Vorschlägen: \nA: Goldman Sax\tB: RTL\nC: Die BILD\tD: Die Datenschutzbestimmungen von Facebook\n\n");
            rant = 'D';
            rechner[9] = 9;
            break;
        default: 
            printf("Fehler!");
            rant = 'x'; //Test
            break;
    }
    
    do {
    printf("A,B,C oder D: ");
    scanf("%c", &eingabe);
    getchar();
}while(eingabe != 'A' && eingabe != 'B' && eingabe != 'C' && eingabe != 'D');
    printf("Ihre eingabe war: >%c<\n\n", eingabe);
    
    //Easter Egg
    if (rant == 'X') {
        printf("Ihre Antwort war leider richtig! *+100 Euronen*\n\n\n");
        euronen = euronen + 100;
    }
    
    //Abfrage: richtiges Ergebnis
    else if (eingabe == rant) {
        printf("Ihre Antwort war leider richtig! *+100 Euronen*\n\n\n");
        euronen = euronen + 100;
    }
    else if(eingabe != rant){
        verloren();
        return 0;
    }
    
    }while(hauptschleife == 0);
        
    
    return 0;
}

//Zufallsmethode
int zufallszahl(int anzahl){
	srand(time(NULL));
	int rueckgabe;
	rueckgabe=("%d ", rand() % anzahl +1);
	return rueckgabe - 1; //Gebe Zufallszahl minus 1 zurück für Array Kompatibelität
}

//Verloren
void verloren(){
    printf("Zum Glück haben Sie 'leider' Verloren!\n(Wer hätte das auch Zahlen sollen)\n\nIhr Highscore: %i Euronen", euronen);
}

//Gewonnen
void gewonnen() {
    printf("Sie haben tatsächlich gewonnen :C\nIch hab jetzt leider kein Geld dabei.. \n\nIhr Highscore: %i Euronen", euronen);
}
