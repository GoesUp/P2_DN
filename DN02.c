#include <stdio.h>

void kodiraj() {
    char countChar = 0;
    char newChar = 0;
    int repeatNo = 1;

    newChar = getchar();
    countChar = newChar;

    while (1) {
        newChar = getchar();
        if (countChar == newChar) {
            repeatNo++;
            continue;
        } else {
            if (countChar == '#') {
                printf("##%d#", repeatNo);
            } else {
                if (repeatNo >= 5) {
                    printf("#%c%d#", countChar, repeatNo);
                } else {
                    for (int i = 0; i < repeatNo; ++i) {
                        printf("%c", countChar);
                    }
                }
            }

            countChar = newChar;
            repeatNo = 1;
            if (newChar == '\n') {
                return;
            }
        }
    }
}

void odkodiraj() {
    char repeatChar = '\0';
    int repeatNo = 0;
    char nextChar;

    while (1) {
        nextChar = getchar();
        if (nextChar == '\n') {
            return;
        } else if (nextChar == '#') {
            scanf("%c%d#", &repeatChar, &repeatNo);
            for (int i = 0; i < repeatNo; ++i) {
                printf("%c", repeatChar);
            }
        } else {
            printf("%c", nextChar);
        }
    }
}

int main() {
    int ukaz;
    scanf("%d ", &ukaz);

    if (ukaz == 1) {
        kodiraj();
    } else if (ukaz == 2) {
        odkodiraj();
    }

    printf("\n");
    return 1;
}