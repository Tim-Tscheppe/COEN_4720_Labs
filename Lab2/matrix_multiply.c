/*
Embedded Systems Lab 2 - Tim Tscheppe
Note that I assumed matrices A, B and C are contstand and always the size specified in the problem statement.
*/

#include <stdio.h>

int main() {

    FILE *fileA, *fileB, *fileC;
    int matrixA[2][4];
    int matrixB[4][2];
    int matrixC[2][2]; 

    fileA = fopen("matrixA.txt", "r");
    fileB = fopen("matrixB.txt", "r");

    if (fileA == NULL || fileB == NULL) {
        printf("Error opening input files");
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            fscanf(fileA, "%d", &matrixA[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            fscanf(fileB, "%d", &matrixB[i][j]);
        }
    }

    fclose(fileA);
    fclose(fileB);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    fileC = fopen("matrixC.txt", "w");

    if (fileC == NULL) {
        printf("Error opening output file");
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            fprintf(fileC, "%d ", matrixC[i][j]);
        }
        fprintf(fileC, "\n");
    }

    fclose(fileC);

    printf("Matrix multiplication completed and result is stored in matrixC.txt.\n");

    return 0;
}

