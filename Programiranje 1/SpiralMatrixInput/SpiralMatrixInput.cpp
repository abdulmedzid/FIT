#include <iostream>
#include <iomanip>
using namespace std;

const int rows = 5;
const int cols = 5;

void spiralInputMatrix(int[][cols]);
void outputMatrix(int[][cols]);

int main() {

    int mat[rows][cols];
    spiralInputMatrix(mat);
    outputMatrix();
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
    }
}

void outputMatrix(int mat[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cout << setw(3) << mat[i][j] << " ";
        }
        cout << endl;
    }
}