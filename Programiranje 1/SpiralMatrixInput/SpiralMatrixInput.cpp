#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Problem: Enable spiral input to the matrix
 * and check symetry with regards to center
 * primary diagonal and secundary diagonal
*/

// change based on input
const int rows = 5;
const int cols = 5;

void spiralInputMatrix(int[][cols]);
bool isMatrixSymetricalWithRegardsToCenter(int[][cols]);
bool isMatrixSymetricalWithRegardsToPrimaryDiagonal(int[][cols]);
bool isMatrixSymetricalWithRegardsToSecundaryDiagonal(int[][cols]);
void outputMatrix(int[][cols]);

int main() {

    int mat[rows][cols];
    spiralInputMatrix(mat);
    outputMatrix(mat);

    if (isMatrixSymetricalWithRegardsToCenter(mat)) {
        cout << " * Matrix is symetrical with regards to center." << endl;
    }

    if (isMatrixSymetricalWithRegardsToPrimaryDiagonal(mat)) {
        cout << " * Matrix is symetrical with regards to primary diagonal." << endl;
    }

    if (isMatrixSymetricalWithRegardsToSecundaryDiagonal(mat)) {
        cout << " * Matrix is symetrical with regards to secundary diagonal." << endl;
    }

    return 0;
}

void spiralInputMatrix(int mat[][cols]) {

    int
        topRow = 0,
        bottomRow = rows-1,
        leftCol = 0,
        rightCol = cols-1;

    while (topRow <= bottomRow && leftCol <= rightCol) {
        
        // top row
        for (int i = leftCol; i <= rightCol; i++) {
            cin >> mat[topRow][i];
        }

        // right col
        for (int i = topRow+1; i <= bottomRow; i++) {
            cin >> mat[i][rightCol];
        }

        // bottom row
        if (topRow != bottomRow) {
            for (int i = rightCol-1; i > leftCol; i--) {
                cin >> mat[bottomRow][i];
            }
        }

        // left col
        if (leftCol != rightCol) {
            for (int i = bottomRow; i > topRow; i--) {
                cin >> mat[i][leftCol];
            }
        }

        topRow++;
        bottomRow--;
        leftCol++;
        rightCol--;
    }
}

bool isMatrixSymetricalWithRegardsToCenter(int mat[][cols]) {

    float centerRow = (rows-1) / 2.0;
    float centerCol = (cols-1) / 2.0;

    /**
     * Nested for loops check symetricality
     * of the top half to the bottom half
     * */
    for (int i = 0; i <= centerCol; i++) {
        for (int j = 0; j < cols; j++) {
            int a = mat[i][j];
            int _aRow = centerRow + (centerRow - i);
            int _aCol = centerCol + (centerCol - j);
            int _a = mat[_aRow][_aCol];
            if (a != _a) {
                return false;
            }
        }
    }

    /**
     * If there is odd number of rows
     * then the symetricality of the
     * center row was left unchecked
     * */
    if (rows&1) {
        for (int i = 0; i <= centerCol; i++) {
            int a = mat[(int)centerRow][i];
            int _aCol = centerCol + (centerCol - i);
            int _a = mat[(int)centerRow][_aCol];
            if (a != _a) {
                return false;
            }
        }
    }

    return true;
}

bool isMatrixSymetricalWithRegardsToPrimaryDiagonal(int mat[][cols]) {
    
    if (rows != cols) {
        return false;
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != mat[j][i]) {
                return false;
            }
        }
    }

    return true;
}

bool isMatrixSymetricalWithRegardsToSecundaryDiagonal(int mat[][cols]) {
    
    if (rows != cols) {
        return false;
    }

    for (int i = 0; i < rows-1; i++) {
        for (int j = 0; j < cols-i-1; j++) {
            int a = mat[i][j];
            int _a = mat[cols-1-i][rows-1-j];
            if (a != _a) {
                return false;
            }
        }
        cout << endl;
    }

    return true;
}

void outputMatrix(int mat[][cols]) {

    cout << "---" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cout << setw(3) << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---" << endl;
}