#include <stdio.h>
#include <stdlib.h>

int rekurzija(char *vzorec, char *besedilo) {
    if ((*vzorec == '\0') && (*besedilo == '\0')) {
        return 1;
    } else if ((*vzorec == '\0') || (*besedilo == '\0')) {
        if ((*vzorec == '*') && (*besedilo == '\0')) return rekurzija(vzorec + 1, besedilo);
        return 0;
    }

    if (*vzorec == '?') {
        return rekurzija(vzorec + 1, besedilo + 1);
    } else if (*vzorec == '*') {
        return rekurzija(vzorec, besedilo + 1) || rekurzija(vzorec + 1, besedilo);
    }
    return (*vzorec == *besedilo) && (rekurzija(vzorec + 1, besedilo + 1));
}

void skenslajZvezdice(char **potDoVzorca) {
    char *vzorec = *potDoVzorca;
    char *noviString = (char *) calloc(101, sizeof(char *));
    *noviString = *(vzorec++);
    int kolicinaZnakov = 1;

    while (*vzorec != '\0') {
        if ((*vzorec != '*') || (*(noviString + kolicinaZnakov - 1) != '*')) {
            *(noviString + kolicinaZnakov++) = *vzorec;
        }
        vzorec++;
    }

    *potDoVzorca = noviString;
}

int main() {
    char *vzorec = (char *) calloc(101, sizeof(char *));
    scanf("%s", vzorec);
    skenslajZvezdice(&vzorec); // Nadomesti večkratne zaporedne pojavitve zvezdic z eno samo zvezdico.

    int ponovitev;
    scanf("%d", &ponovitev);

    int rezultat = 0;
    for (int i = 0; i < ponovitev; i++) {
        char *vrstica = (char *) calloc(101, sizeof(char *));
        scanf("%s", vrstica);
        rezultat += rekurzija(vzorec, vrstica);
        free(vrstica);
    }

    free(vzorec);
    printf("%d\n", rezultat);
}