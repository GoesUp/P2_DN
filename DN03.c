#include <stdio.h>
#include <stdlib.h>

int getSnackType(int locX, int locY, int *snaxX, int *snaxY, int *snaxT, int numberOfSnax) {
    for (int i = 0; i < numberOfSnax; ++i) {
        if ((*(snaxX + i) == locX) && (*(snaxY + i) == locY)) {
            return *(snaxT + i);
        }
    }
    return 0;
}

void moveTheSnake(int *snakeX, int *snakeY, int snakeDirectionX, int snakeDirectionY, int snakeLen, int currentSnack) {
    for (int i = (currentSnack == 0) ? (snakeLen - 1) : (snakeLen); i > 0; i--) {
        *(snakeX + i) = *(snakeX + i - 1);
        *(snakeY + i) = *(snakeY + i - 1);
    }
    *snakeX += snakeDirectionX;
    *snakeY += snakeDirectionY;
}

int checkSnakeBite(int *snakeX, int *snakeY, int snakeLen) {
    int headX = *snakeX;
    int headY = *snakeY;

    for (int i = 1; i < snakeLen; i++) {
        if ((*(snakeX + i) == headX) && (*(snakeY + i) == headY)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Crucial snake data
    int snakeLen = 1;
    int snakeDirectionX = 0;
    int snakeDirectionY = 1;

    // Snake body parts locations :)
    int *snakeX = (int *) malloc(1000 * sizeof(int));
    int *snakeY = (int *) malloc(1000 * sizeof(int));
    *snakeX = 0;
    *snakeY = 0;

    int numberOfSnacks;
    scanf("%d", &numberOfSnacks);

    // Location and data of snacks
    int *snackLocX = (int *) malloc(numberOfSnacks * sizeof(int));
    int *snackLocY = (int *) malloc(numberOfSnacks * sizeof(int));
    int *snackType = (int *) malloc(numberOfSnacks * sizeof(int));
    for (int i = 0; i < numberOfSnacks; i++) {
        scanf("%d %d %d", snackLocX + i, snackLocY + i, snackType + i);
    }

    int steps;
    scanf("%d", &steps);

    for (int j = 0; j < steps; ++j) {
        // Determine if we happen to stand on a snack.
        int currentSnack = getSnackType(*snakeX, *snakeY, snackLocX, snackLocY, snackType, numberOfSnacks);

        // Change snake direction should the snake's head land on one of the special snacks.
        if (currentSnack == 2) {
            if (snakeDirectionX == 0 && snakeDirectionY == 1) {
                snakeDirectionX = -1;
                snakeDirectionY = 0;
            } else if (snakeDirectionX == -1 && snakeDirectionY == 0) {
                snakeDirectionX = 0;
                snakeDirectionY = -1;
            } else if (snakeDirectionX == 0 && snakeDirectionY == -1) {
                snakeDirectionX = 1;
                snakeDirectionY = 0;
            } else if (snakeDirectionX == 1 && snakeDirectionY == 0) {
                snakeDirectionX = 0;
                snakeDirectionY = 1;
            }
        } else if (currentSnack == 3) {
            if (snakeDirectionX == 0 && snakeDirectionY == 1) {
                snakeDirectionX = 1;
                snakeDirectionY = 0;
            } else if (snakeDirectionX == 1 && snakeDirectionY == 0) {
                snakeDirectionX = 0;
                snakeDirectionY = -1;
            } else if (snakeDirectionX == 0 && snakeDirectionY == -1) {
                snakeDirectionX = -1;
                snakeDirectionY = 0;
            } else if (snakeDirectionX == -1 && snakeDirectionY == 0) {
                snakeDirectionX = 0;
                snakeDirectionY = 1;
            }
        }

        moveTheSnake(snakeX, snakeY, snakeDirectionX, snakeDirectionY, snakeLen, currentSnack);
        if (currentSnack == 1) {
            snakeLen++;
        }
        int bite = checkSnakeBite(snakeX, snakeY, snakeLen);
        if (bite == 1) {
            printf("%d %d %d\n", 0, *snakeX, *snakeY);
            return 0;
        }
    }

    printf("%d %d %d\n", snakeLen, *snakeX, *snakeY);
    return 0;
}