#include <stdio.h>

#define MAX_ROWS 4
#define MAX_COLS 5

int main() {
    // 1. Define a standard 4x5 2D matrix with mostly zero values
    int normalMatrix[MAX_ROWS][MAX_COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int nonZeroCount = 0;

    // 2. Count the number of non-zero elements
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (normalMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // 3. Define the triplet representation matrix (compact matrix)
    // Rows: nonZeroCount + 1 (Header row stores overall matrix metadata)
    // Columns: 3 (Row index, Column index, Value)
    int tripletMatrix[nonZeroCount + 1][3];

    // 4. Initialize the header row (Row 0)
    tripletMatrix[0][0] = MAX_ROWS;       // Total rows in original matrix
    tripletMatrix[0][1] = MAX_COLS;       // Total columns in original matrix
    tripletMatrix[0][2] = nonZeroCount;   // Total non-zero elements

    // 5. Populate the compact triplet matrix with non-zero elements
    int k = 1; // Start from row 1 since row 0 is the header
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (normalMatrix[i][j] != 0) {
                tripletMatrix[k][0] = i;                 // Store Row Index
                tripletMatrix[k][1] = j;                 // Store Column Index
                tripletMatrix[k][2] = normalMatrix[i][j]; // Store Value
                k++;
            }
        }
    }

    // 6. Display the Triplet Representation
    printf("Triplet Representation (Row, Column, Value):\n");
    printf("---------------------------------------------\n");
    printf("Row\tCol\tValue\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i <= nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", tripletMatrix[i][0], tripletMatrix[i][1], tripletMatrix[i][2]);
    }

    return 0;
}
