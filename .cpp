#include <iostream>
#include <vector> //using vector
#include <algorithm> //to use *min_element(line 48)
using namespace std;


vector<int> list;
struct element {
    int row;
    int col;
    int value;
};


void inputMatrisA(element matrisA[], int size) {
    cout << "matris A:\n";
    for (int i = 0; i < size; i++) {
        cout << "element " << i + 1 << ":\n";
        cout << "row: ";
        cin >> matrisA[i].row;
        cout << "col: ";
        cin >> matrisA[i].col;
        cout << "value: ";
        cin >> matrisA[i].value;
    }
}


void inputMatrisB(element matrisB[], int size) {
    cout << "matrid B:\n";
    for (int i = 0; i < size; i++) {
        cout << "value " << i + 1 << ":\n";
        cout << "row: ";
        cin >> matrisB[i].row;
        cout << "col: ";
        cin >> matrisB[i].col;
        cout << "value: ";
        cin >> matrisB[i].value;
    }
}

void matrisSparseA(element matrisA[], element matrisSparseA[], int size) {
    vector<int> rowList;
    for (int i = 0; i < size; ++i) {
        rowList.push_back(matrisA[i].row); //to append rows to wolist
    }

    for (int i = 0; i < size; ++i) {
        int minRow = *min_element(rowList.begin(), rowList.end()); //to find minimum row
        int index = -1; //when something will be added to rowist, te index will be increases and the index of the first row will be 0

        // Find the original element with this row
        for (int j = 0; j < size; ++j) {//to find minimum of rowlist
            if (matrisA[j].row == minRow) {
                index = j;
                break;
            }
        }

        // Transpose: swap row and col
        matrisSparseA[i].row = matrisA[index].col;//spare matrie arrange according to min to max rowlist 
        matrisSparseA[i].col = matrisA[index].row;
        matrisSparseA[i].value = matrisA[index].value;

        cout << i << "th A" << endl;
        cout << "[" << matrisSparseA[i].row << ", " << matrisSparseA[i].col << ", " << matrisSparseA[i].value << "]" << endl;

        rowList.erase(remove(rowList.begin(), rowList.end(), minRow), rowList.end()); //remove used element and starting new loop
    }
}

void matrisSparseB(element matrisB[], element matrisSparseB[], int size) {
    vector<int> rowList;
    for (int i = 0; i < size; ++i) {
        rowList.push_back(matrisB[i].row); //to append rows to wolist
    }

    for (int i = 0; i < size; ++i) {
        int minRow = *min_element(rowList.begin(), rowList.end()); //to find minimum row
        int index = -1; //when soething will be added to rowist, te index will be pused by 1 and the index of the first row will be 0


        for (int j = 0; j < size; ++j) { //to find minimum of rowlist
            if (matrisB[j].row == minRow) {
                index = j;
                break;
            }
        }

        matrisSparseB[i].row = matrisB[index].col; //spare matrie arrange according to min to max rowlist 
        matrisSparseB[i].col = matrisB[index].row;
        matrisSparseB[i].value = matrisB[index].value;

        cout << i << "th B" << endl;
        cout << "[" << matrisSparseB[i].row << ", " << matrisSparseB[i].col << ", " << matrisSparseB[i].value << "]" << endl;

        rowList.erase(remove(rowList.begin(), rowList.end(), minRow), rowList.end()); //remove used element and starting new loop
    }
}

void sumSparsMatriceAB(element matrisSparseA[], element matrisSparseB[], int size) {
    for (int i = 0; i < size; i++) {
        cout <<"sum function";
        if (matrisSparseA[i].row == matrisSparseB[i].row && matrisSparseA[i].col == matrisSparseB[i].col) {
            int sumValue = matrisSparseA[i].value + matrisSparseB[i].value;
            cout << "[" << matrisSparseA[i].col << ", " << matrisSparseA[i].row << ", " << sumValue << "]" << endl;
        } else {
            cout << "[" << matrisSparseA[i].col << ", " << matrisSparseA[i].row << ", " << matrisSparseA[i].value << "]" << endl;
            cout << "[" << matrisSparseB[i].col << ", " << matrisSparseB[i].row << ", " << matrisSparseB[i].value << "]" << endl;
        }
    }
}

int main() {
    element matrisA[1], matrisB[1], sparsMatrisA[1], sparsMatrisB[1];
    inputMatrisA(matrisA, 1);
    inputMatrisB(matrisB, 1);
    matrisSparseA(matrisA, sparsMatrisA, 1);
    matrisSparseB(matrisB, sparsMatrisB, 1);
    sumSparsMatriceAB(sparsMatrisA, sparsMatrisB, 1);
}
