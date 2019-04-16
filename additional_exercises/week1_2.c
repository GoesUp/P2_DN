#include <stdio.h>
#include <math.h>

int main() {
    int value = 0;
    char binaryNumber;
    
    while (1) {
        binaryNumber = getchar();
        if (binaryNumber == '\n') {
            break;
        }

        value = value * 2 + binaryNumber - '0';
    }

    printf("%f", ceil(log2(value)));
    return 0;
}