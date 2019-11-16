#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>
using namespace std;

const int rows = 10;
const int cols = 10;

void outputMatrix(int [][cols]);
void fillMatrix(int [][cols]);
void sortMatrix(int [][cols], int, char, char, char);
bool isValidForSwap(int, int, char, char);
bool isValidForSwap(float, float, char);
void swapRows(int [], int []);
void swapColumns(int [][cols], int, int);
int getSecondDigitFromLeft(int);
int getSecondDigitFromRight(int);
int getNumberOfDigits(int);
float getMiddleDigit(int);

int main() {

    int mat[rows][cols];
    int sortingLine;

    /**
     * Sort by row ('r') or column ('c')
    */
    char sortingDimension;

    /**
     * Sort by number ('n'), 
     * middle digit ('m'),
     * second digit from left ('l') 
     * and second digit from right ('r')
    */
    char sortingFactor;

    /**
     * Ascending sort ('a')
     * or descending sort ('d')
    */
    char sortingMode;

    fillMatrix(mat);
    outputMatrix(mat);

    do {
        cout << "Enter whether you would like to sort by row or column (r/c): ";
        cin >> sortingDimension;
    } while (sortingDimension != 'r' && sortingDimension != 'c');

    do {
        cout << "Enter wether you would like to sort by:" << endl
             << "number (n)" << endl
             << "middle digit (m)" << endl
             << "second digit from left (l)" << endl 
             << "second digit from right (r)" << endl
             << ">";
        cin >>  sortingFactor;
    } while (sortingFactor != 'n' && sortingFactor != 'm' && sortingFactor != 'l' && sortingFactor != 'r');

    do {
        cout << "Enter wether you would like to sort:" << endl
             << "ascending (a)" << endl
             << "descending (d)" << endl
             << ">";
        cin >> sortingMode;
    } while (sortingMode != 'a' && sortingMode != 'd');

    do {
        cout << "Enter " << (sortingDimension == 'r' ? "row" : "column") << " to sort by: ";
        cin >> sortingLine;
    } while (sortingLine < 1 || sortingLine > rows && sortingDimension == 'r' || sortingLine > cols && sortingDimension == 'c');
    sortingLine--;

    sortMatrix(mat, sortingLine, sortingDimension, sortingFactor, sortingMode);
    outputMatrix(mat);

    return 0;
}

void outputMatrix(int mat[][cols]) {
    //system("cls");
    cout << "---" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(7) << mat[i][j];
        }
        cout << endl;
    }
    cout << "---" << endl;
    //Sleep(200);
}

void fillMatrix(int mat[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % 1000000 + 100;
        }
    }
}

void sortMatrix(int mat[][cols], int sortingLine, char sortingDimension, char sortingFactor, char sortingMode) {
    int len = sortingDimension == 'r' ? cols-1 : rows-1;
    int numOfPasses = 0;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < len-numOfPasses; i++) {
            if (sortingDimension == 'r' && isValidForSwap(mat[sortingLine][i], mat[sortingLine][i+1], sortingFactor, sortingMode)) {
                swapColumns(mat, i, i+1);
                isSorted = false;
            } else if (sortingDimension == 'c' && isValidForSwap(mat[i][sortingLine], mat[i+1][sortingLine], sortingFactor, sortingMode)) {
                swapRows(mat[i], mat[i+1]);
                isSorted = false;
            }
        }
        numOfPasses++;
    }
}

bool isValidForSwap(int a, int b, char sortingFactor, char sortingMode) {
    switch (sortingFactor) {
        case 'm': 
            return isValidForSwap(getMiddleDigit(a), getMiddleDigit(b), sortingMode);
        case 'r':
            return isValidForSwap(getSecondDigitFromRight(a), getSecondDigitFromRight(b), sortingMode);
        case 'l':
            return isValidForSwap(getSecondDigitFromLeft(a), getSecondDigitFromLeft(b), sortingMode);
        case 'n':
        default:
            return isValidForSwap(a, b, sortingMode);
    }
}

bool isValidForSwap(float a, float b, char sortingMode) {
    return a > b && sortingMode == 'a' || a < b && sortingMode == 'd';
}

void swapRows(int rowA[cols], int rowB[cols]) {
    for (int i = 0; i < cols; i++) {
        int temp = rowA[i];
        rowA[i] = rowB[i];
        rowB[i] = temp;
    }
}

void swapColumns(int mat[][cols], int colA, int colB) {
    for (int i = 0; i < rows; i++) {
        int temp = mat[i][colA];
        mat[i][colA] = mat[i][colB];
        mat[i][colB] = temp;
    }
}

float getMiddleDigit(int num) {
    int numOfDigits = getNumberOfDigits(num);
    float middleDiggit;
    if (numOfDigits&1) {
        num = num / pow(10, numOfDigits / 2);
        middleDiggit = num%10;
    } else {
        num = num / pow(10, numOfDigits / 2 - 1);
        middleDiggit = num % 10;
        middleDiggit += num/10%10;
        middleDiggit /= 2;
    }
    return middleDiggit;
}

int getSecondDigitFromRight(int num) {
    return num/10%10;
}

int getSecondDigitFromLeft(int num) {
    int numOfDigits = getNumberOfDigits(num);
    int secondDigit = num / (int) pow(10, numOfDigits - 2) % 10;
    return secondDigit;
}

int getNumberOfDigits(int num) {
    if (num == 0) return 1;
    return log10(num) + 1;
}