#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

vector<int> getRows(int rowIndex) {
    if (rowIndex == 0){
        return {1};
    } else if (rowIndex == 1) {
        return {1,1};
    } else {
        vector<int> row = {1};
        vector<int> prevRow = getRows(rowIndex-1);
        for (int i = 0 ; i < prevRow.size()-1 ; i++){
            row.push_back(prevRow[i] + prevRow[i+1]);
        }
        row.push_back(1);
        return row;
    }
}

vector<int> getRow(int rowIndex) {
    vector<int> rows(rowIndex+1, 1);
    for (int i = 1 ; i < rowIndex ; i++){
        for (int j = rowIndex-i ; j < rowIndex ; j++){
            rows[j] = rows[j] + rows[j+1];
        }
    }
    return rows;
}

int main(){
    int rowIndex;
    vector<int> row;

    rowIndex = 2;
    row = getRow(rowIndex);
    printf("index: %d\n", rowIndex);
    printVector(row);
    assert(row == getRows(rowIndex));

    rowIndex = 4;
    row = getRow(rowIndex);
    printf("index: %d\n", rowIndex);
    printVector(row);
    assert(row == getRows(rowIndex));

    rowIndex = 0;
    row = getRow(rowIndex);
    printf("index: %d\n", rowIndex);
    printVector(row);
    assert(row == getRows(rowIndex));

    rowIndex = 3;
    row = getRow(rowIndex);
    printf("index: %d\n", rowIndex);
    printVector(row);
    assert(row == getRows(rowIndex));


    return 0;
}
