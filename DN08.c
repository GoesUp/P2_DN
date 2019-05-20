#include <stdio.h>
#include <malloc.h>

int memberToInt(char memberNum) {
    if (memberNum == 'L') return 0;
    if (memberNum == 'C') return 1;
    if (memberNum == 'D') return 2;
}


long long rekurzija(char memberLeft, int le, int de, int ce, long long ****arr) {
    if (arr[le][de][ce][memberToInt(memberLeft)] != -1) {
        return arr[le][de][ce][memberToInt(memberLeft)];
    }

    if (le + ce + de == 0) {
        arr[le][de][ce][memberToInt(memberLeft)] = 1;
        return 1;
    }

    long long vsota = 0;

    if (memberLeft == 'D') {
        if (de + ce == 0) {
            arr[le][de][ce][memberToInt(memberLeft)] = 0;
            return 0;
        }

        if (de > 0) {
            vsota += rekurzija('D', le, de - 1, ce, arr);
        }

        if (ce > 0) {
            vsota += rekurzija('C', le, de, ce - 1, arr);
        }
    }

    if (memberLeft == 'L') {
        if (le + ce == 0) {
            arr[le][de][ce][memberToInt(memberLeft)] = 0;
            return 0;
        }

        if (le > 0) {
            vsota += rekurzija('L', le - 1, de, ce, arr);
        }

        if (ce > 0) {
            vsota += rekurzija('C', le, de, ce - 1, arr);
        }
    }

    if (memberLeft == 'C' || memberLeft == '\0') {
        if (le > 0) {
            vsota += rekurzija('L', le - 1, de, ce, arr);
        }

        if (ce > 0) {
            vsota += rekurzija('C', le, de, ce - 1, arr);
        }

        if (de > 0) {
            vsota += rekurzija('D', le, de - 1, ce, arr);
        }
    }

    arr[le][de][ce][memberToInt(memberLeft)] = vsota;
    return vsota;
}

int main() {
    int le, de, ce;

    long long ****arr = (long long ****) malloc(21 * sizeof(long long ***));
    for (int i = 0; i <= 20; i++) {
        arr[i] = (long long ***) malloc(21 * sizeof(long long **));
        for (int j = 0; j <= 20; j++) {
            arr[i][j] = (long long **) malloc(21 * sizeof(long long *));
            for (int k = 0; k <= 20; k++) {
                arr[i][j][k] = (long long *) malloc(3 * sizeof(long long));
                for (int l = 0; l < 3; l++) {
                    arr[i][j][k][l] = -1;
                }
            }
        }
    }

    scanf("%d %d %d", &le, &de, &ce);
    printf("%lld\n", rekurzija('\0', le, de, ce, arr));
}