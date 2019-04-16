#include <stdio.h>

int main() {
    int allowPlusMinus = 1;
    int allowZero = 1;
    int mustEnd = 0;
    int numberOfChars = 0;
    char c;

    while (1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (mustEnd) {
            putchar('0');
            putchar('\n');
            return 0;
        }
        numberOfChars++;

        if (allowPlusMinus) {
            allowPlusMinus = 0;
            if (c != '+' && c != '-') {
                if (c == '0') {
                    allowZero = 0;
                    allowPlusMinus = 0;
                    mustEnd = 1;
                } else {
                    if (c < '0' || c > '9') {
                        putchar('0');
                        putchar('\n');
                        return 0;
                    } else {
                        allowZero = 0;
                    }
                }
            }
        } else if (allowZero == 0 && numberOfChars < 3 && c == '0') {
            putchar('0');
            putchar('\n');
            return 0;
        } else {
            if (c < '0' || c > '9') {
                putchar('0');
                putchar('\n');
                return 0;
            }
        }
    }
    if (numberOfChars == 0) {
        putchar('0');
        putchar('\n');
        return 0;
    } else if (numberOfChars == 1 && allowPlusMinus == 0 && allowZero == 1) {
        putchar('0');
        putchar('\n');
        return 0;
    }
    putchar('1');
    putchar('\n');
    return 0;
}