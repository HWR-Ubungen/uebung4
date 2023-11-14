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
    }
    printf("%d", r);
    return r;
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

int geschwindigkeit() {
    char auswahl;
    float speed;
    printf("Was wollen sie umrechnen?\n");
    printf("(a) km/h in mph\n");
    printf("(b) mph in km/h\n");
    scanf("%s", &auswahl);
    printf("Geschwindigkeit eingeben!\n");
    scanf("%f", &speed);

    switch (auswahl)
    {
        case 'a':
            printf("Die Geschwindigkeit entspricht %f mph.\n", (speed*0.621371f));
            break;
        case 'b':
            printf("Die Geschwindigkeit entspricht %f km/h.\n", (speed*1.60934f));
            break;
        default:
            printf("Keine gueltige Eingabe!\n");
    }
    return 0;
}

int temperatur() {
    char auswahl;
    float temp;
    printf("Was wollen sie umrechnen?\n");
    printf("(a) Grad C\n");
    printf("(b) Grad F\n");
    printf("(c) K\n");
    scanf("%s", &auswahl);
    printf("Temperatur eingeben!\n");
    scanf("%f", &temp);

    switch (auswahl)
    {
        case 'a':
            printf("Die Temperatur entspricht %f Grad F.\n", (temp*1.8f+32.0f));
            printf("Die Temperatur entspricht %f K.\n", (temp+273.15f));
            break;
        case 'b':
            printf("Die Temperatur entspricht %f Grad C.\n", ((temp-32.0f)*(0.55555555f)));
            printf("Die Temperatur entspricht %f K.\n", ((temp-32.0f)*(0.55555555f)+273.15f));
            break;
        case 'c':
            printf("Die Temperatur entspricht %f Grad C.\n", (temp-273.15f));
            printf("Die Temperatur entspricht %f Grad F.\n", ((temp-273.15f)*1.8f+32.0f));
            break;
        default:
            printf("Keine gueltige Eingabe!");
    }
    return 0;
}

int byte() {
    char auswahl;
    float b;
    printf("Was wollen sie umrechnen?\n");
    printf("(a) B\n");
    printf("(b) KB\n");
    printf("(c) MB\n");
    printf("(d) GB\n");
    scanf("%s", &auswahl);
    printf("Giga-/Mega-/Kilo-/Bytes eingeben!\n");
    scanf("%f", &b);

    switch (auswahl)
    {
        case 'a':
            printf("Die Bytes entsprechen %f KB.\n", (b/1024.0f));
            printf("Die Bytes entsprechen %f MB.\n", (b/1048576.0f));
            printf("Die Bytes entsprechen %f GB.\n", (b/1073741824.0f));
            break;
        case 'b':
            printf("Die KB entsprechen %f B.\n", (b*1024.0f));
            printf("Die KB entsprechen %f MB.\n", (b/1024.0f));
            printf("Die KB entsprechen %f GB.\n", (b/1048576.0f));
            break;
        case 'c':
            printf("Die MB entsprechen %f B.\n", (b*1048576.0f));
            printf("Die MB entsprechen %f KB.\n", (b*1024.0f));
            printf("Die MB entsprechen %f GB.\n", (b/1024.0f));
            break;
        case 'd':
            printf("Die GB entsprechen %f B.\n", (b*1073741824.0f));
            printf("Die GB entsprechen %f KB.\n", (b*1048576.0f));
            printf("Die GB entsprechen %f MB.\n", (b*1024.0f));
            break;
        default:
            printf("Keine gueltige Eingabe!");
    }
    return 0;
}

int aufgabe6() {
    char auswahl;
    printf("Was wollen sie umrechnen?\n");
    printf("(a) km/h <-> mph\n");
    printf("(b) Grad C <-> Grad F <-> K\n");
    printf("(c) B <-> KB <-> MB <-> GB\n");
    scanf("%c", &auswahl);

    switch (auswahl)
    {
        case 'a':
            geschwindigkeit();
            break;
        case 'b':
            temperatur();
            break;
        case 'c':
            byte();
            break;
        default:
            printf("Keine gueltige Eingabe!");
    }
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
