/* Bismillah ir-Rahman ir-Rahim */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int rows = 5;
const int cols = 5;

void output(int mat[][cols]);
void fillMatrixFromTopLeft(int mat[][cols]);
void fillMatrixFromBottomRight(int mat[][cols]);

int main() {
    int mat[rows][cols] = {0},
        startingPoint;

    do {
        cout << "Enter starting point." << endl
             << "For top left enter 0." << endl
             << "For bottom right enter 1." << endl
             << ">";
        cin >> startingPoint;
    } while(startingPoint != 0 && startingPoint != 1);

    if (startingPoint == 0) {
        fillMatrixFromTopLeft(mat);
    } else if (startingPoint == 1) {
        fillMatrixFromBottomRight(mat);
    }

    output(mat);

    return 0;
}

void output(int mat[][cols]) {
    int widthOfBiggestNumber = log10(rows*cols) + 1; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(widthOfBiggestNumber) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrixFromTopLeft(int mat[][cols]) {
    int
        topRow = 0,
        bottomRow = rows-1,
        leftCol = 0,
        rightCol = cols-1,
        increment = 0;

        while (topRow <= bottomRow && leftCol <= rightCol) {

            // top row
            for  (int i = leftCol; i <= rightCol; i++) {
                mat[topRow][i] = ++increment;
            }

            // right col
            for (int i = topRow+1; i <= bottomRow; i++) {
                mat[i][rightCol] = ++increment;
            }

            // bottom row
            // if topRow is equal to bottomRow it has already been filled
            if (bottomRow != topRow) {
                for (int i = rightCol-1; i > leftCol; i--) {
                    mat[bottomRow][i] = ++increment;
                }
            }

            // left col
            // if leftCol is equal to rightCol it has already been filled
            if (leftCol != rightCol) {
                for (int i = bottomRow; i > topRow; i--) {
                    mat[i][leftCol] = ++increment;
                }
            }

            topRow++;
            bottomRow--;
            leftCol++;
            rightCol--;
        }
}

void fillMatrixFromBottomRight(int mat[][cols]) {
    int
        topRow = 0,
        bottomRow = rows-1,
        leftCol = 0,
        rightCol = cols-1,
        increment = 0;

        while (topRow <= bottomRow && leftCol <= rightCol) {

            // bottom row
            for  (int i = rightCol; i >= leftCol; i--) {
                mat[bottomRow][i] = ++increment;
            }

            // left col
            for (int i = bottomRow-1; i >= topRow; i--) {
                mat[i][leftCol] = ++increment;
            }

            // top row
            // if topRow is equal to bottom row it has already been filled
            if (topRow != bottomRow) {
                for (int i = leftCol+1; i < rightCol; i++) {
                    mat[topRow][i] = ++increment;
                }
            }

            // right col
            // if rightCol is equal to leftCol it has already been filled
            if (rightCol != leftCol) {
                for (int i = topRow; i < bottomRow; i++) {
                    mat[i][rightCol] = ++increment;
                }
            }

            topRow++;
            bottomRow--;
            leftCol++;
            rightCol--;
        }
}