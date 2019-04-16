#include <stdio.h>

int main() {
    char firstChar = getchar();

    int modeOne = 0;
    int modeTwo = 0;
    int modeThree = 0;
    int modeFour = 0;
    int danger = 1;

    if (firstChar == '0') {
        char nextChar = getchar();
        if (nextChar == '\n') {
            putchar('1');
            putchar('\n');
            return 0;
        } else if (nextChar == 'x') {
            modeThree = 1;
        } else if (nextChar == 'b') {
            modeFour = 1;
        } else if (nextChar > '0' && nextChar < '8') {
            modeTwo = 1;
        } else {
            putchar('0');
            putchar('\n');
            return 0;
        }
    } else if (firstChar >= '1' && firstChar <= '9') {
        modeOne = 1;
    } else {
        putchar('0');
        putchar('\n');
        return 0;
    }

    while (1) {
        char nextChar = getchar();
        if (nextChar == '\n') {
            if (danger == 1 && modeOne == 0 && modeTwo == 0) {
                putchar('0');
                putchar('\n');
                return 0;
            }
            putchar('1');
            putchar('\n');
            return 0;
        }
        danger = 0;

        if (modeOne == 1) {
            if (nextChar < '0' || nextChar > '9') {
                putchar('0');
                putchar('\n');
                return 0;
            }
        } else if (modeTwo == 1) {
            if (nextChar < '0' || nextChar > '7') {
                putchar('0');
                putchar('\n');
                return 0;
            }
        } else if (modeThree == 1) {
            if ((nextChar < '0' || nextChar > '9') && (nextChar < 'A' || nextChar > 'F')) {
                putchar('0');
                putchar('\n');
                return 0;
            }
        } else if (modeFour == 1) {
            if (nextChar != '0' && nextChar != '1') {
                putchar('0');
                putchar('\n');
                return 0;
            }
        }
    }

    putchar('1');
    putchar('\n');
    return 0;
}