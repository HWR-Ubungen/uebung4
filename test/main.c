#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sysinfoapi.h>
#include <timeapi.h>

void aufgabe1() {
    int num1, num2;
    printf("Erste Zahl eingeben: ");
    scanf("%d", &num1);
    printf("Zweite Zahl eingeben: ");
    scanf("%d", &num2);
    if (num1 > num2) {
        printf("%d", num1);
    } else {
        printf("%d", num2);
    }
}

int aufgabe2() {
    int num1, num2;
    printf("Erste Zahl eingeben: ");
    scanf("%d", &num1);
    printf("Zweite Zahl eingeben: ");
    scanf("%d", &num2);
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int fakRek(int zahl) {
    if (zahl == 0)
        return 1;
    return zahl * (fakRek(zahl-1));
}


int aufgabe3() {
    int r = 1;
    int n = 1;

    printf("Wert eingeben, von dem die Fakultaet berechnet werden soll:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++ ) {
        r = r * i;
    } return r;
}

struct Orte {
    double breitengrad;
    double laengengrad;
} ort1, ort2;

double abstand(){
    //Abstandsberechnung
    printf("Breitengrad für Ort 1 eingeben: ");
    scanf("%lf", &ort1.breitengrad);
    printf("Längengrad für Ort 1 eingeben: ");
    scanf("%lf", &ort1.laengengrad);

    printf("Breitengrad für Ort 2 eingeben: ");
    scanf("%lf", &ort2.breitengrad);
    printf("Längengrad für Ort 2 eingeben: ");
    scanf("%lf", &ort2.laengengrad);

    double breite1 = ort1.breitengrad * M_PI / 180.0;
    double laenge1 = ort1.laengengrad * M_PI / 180.0;
    double breite2 = ort2.breitengrad * M_PI / 180.0;
    double laenge2 = ort2.laengengrad * M_PI / 180.0;

    double gesamtlaenge = laenge2 - laenge1;
    double gesamtbreite = breite2 - breite1;

    double a = pow(sin(gesamtbreite / 2), 2) + cos(breite1) * cos(breite2) * pow(sin(gesamtlaenge / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double radius = 6371;
    double abstand = radius * c;
    printf("Distanz: ");
    printf("%lf",  abstand);
    printf("%s\n", "km");

    //Auswahl des Verkehrsmittels
    char input2;
    double fahrzeit = 0; // in h
    double Aspeed = 100; // km/h
    double Lspeed = 5; // km/h
    double Fspeed = 800; // km/h

    printf("Auswahlmöglichkeiten: A für Auto, L für Laufen, F für Flugzeug: ");
    scanf("%s", &input2);

    switch (input2)
    {
        case 'A':
            fahrzeit = (double)abstand / Aspeed;
            break;
        case 'L':
            fahrzeit = abstand / Lspeed;
            break;
        case 'F':
            fahrzeit = abstand / Fspeed;
            break;
        default:
            printf("Keine gültige Eingabe!");
    }

    printf("Fahrzeit: ");
    printf("%lf", fahrzeit);
    printf("h");

    return 0;
}

char Benutzer [5][2][20];
int m = 0;
bool userRegistered = false;

int registrierung() {
    printf("Registrierung als Benutzer %d: \n", m);
    printf("Benutzername festlegen: ");
    scanf("%19s", &Benutzer[m][0]);

    for (int i = 0; i < m; i++) {
        if (strcmp(Benutzer[m][0], Benutzer[i][0]) == 0) {
            printf("Benutzername bereits belegt!\n");
            userRegistered = true;
        }
    }
    if (userRegistered == false) {
        printf("Passwort festlegen: ");
        scanf("%19s", &Benutzer[m][1]);
        m++;
    }
}

int anmeldung(){



    char benutzername_inp [20];
    char passwort_inp [20];
    printf("Anmeldung als Benutzer1: \n");
    printf("Benutzername eingeben: ");
    scanf("%s", &benutzername_inp);
    int userID = 0;

    int zeilen = 5;
    for (int i = 0; i < zeilen; ++i) {
        if(strcmp(&Benutzer[i][0],benutzername_inp) == 0){
            userID = i;
            i = 10;
        } else if(i == zeilen-1) {
            printf("Benutzer nicht gefunden!");
            userID = 6;
        }
    }

    if (userID != 6) {
        int anmeldeversuche = 3;
        while (anmeldeversuche > 0) {
            printf("Passwort eingeben: ");
            scanf("%s", &passwort_inp);
            if (0 != strcmp(&Benutzer[userID][1], passwort_inp)) {
                printf("Benutzereingabe falsch\n");
                anmeldeversuche--;
            } else {
                printf("Sie sind angemeldet!");
                break;
            }
        }
        if(anmeldeversuche == 0) printf("Zu viele Anmeldeversuche!");
    }
    return 0;
}

int main(){
    //aufgabe1();
    //aufgabe2();
    //aufgabe3();
    //printf("%d", fakRek(5));
    // Aufgabe 4:
    //abstand();
    //
    registrierung();
    registrierung();
    anmeldung();
}
