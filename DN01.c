#include <stdio.h>
#include <math.h>

int getNumLen(long i) {
    int length = 0;
    while (i > 0) {
        i /= 10;
        length++;
    }
    return length;
}

int getFirstNum(long i) {
    while (i >= 10) {
        i /= 10;
    }
    return (int) i;
}

void popFirstNum(int *i) {
    *i = *i - (int) pow(10, getNumLen(*i) - 1) * getFirstNum(*i);
}

int getNthInt(long i, int pos) {
    int counter = 0;
    while (counter < (getNumLen(i) - pos - 1)) {
        i /= 10;
    }
    return (int) (i % 10);
}

int main() {
    long n;
    int m;
    scanf("%ld %d", &n, &m);

    int lenM = getNumLen(m);

    int intPosition = 0;
    for (int i = lenM; i > 0; i--) {
        int numsQuant = getFirstNum(m);
        popFirstNum(&m);

        int newNum = 0;
        for (int j = 0; j < numsQuant; j++) {
            newNum = newNum * 10 + getNthInt(n, intPosition);
            intPosition++;
        }
        printf("%d\n", newNum);
    }

    return 0;
}


