#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

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
    registrierung();
    registrierung();
    anmeldung();
}