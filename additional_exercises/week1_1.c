#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    
    int aNeg = 0;
    int bNeg = 0;

    char nextChar;

    while (1) {
        nextChar = getchar();

        if (nextChar == '-') {
            aNeg = 1;
        } else if (nextChar == ' ') {
            break;
        } else {
            a = a * 10 + nextChar - '0';
        }
    }

    if (aNeg) {
        a *= -1;
    }

    while (1) {
        nextChar = getchar();

        if (nextChar == '-') {
            bNeg = 1;
        } else if (nextChar == '\n') {
            break;
        } else {
            b = b * 10 + nextChar - '0';
        }
    }

    if (bNeg) {
        b *= -1;
    }

    printf("%d\n", a + b);
    return 0;
}