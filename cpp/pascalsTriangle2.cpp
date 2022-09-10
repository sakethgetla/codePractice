#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

vector<int> getRow(int rowIndex) {
    if (rowIndex == 0){
        return {1};
    } else if (rowIndex == 1) {
        return {1,1};
    } else {
        vector<int> row = {1};
        vector<int> prevRow = getRow(rowIndex-1);
        for (int i = 0 ; i < prevRow.size()-1 ; i++){
            row.push_back(prevRow[i] + prevRow[i+1]);
        }
        row.push_back(1);
        return row;
    }


}

int main(){
    int rowIndex;
    vector<int> row;

    rowIndex = 4;
    row = getRow(rowIndex);
    printf("index: %d\n", rowIndex);
    printVector(row);

    rowIndex = 0;
    row = getRow(rowIndex);
    printf("index: %d\n", rowIndex);
    printVector(row);

    rowIndex = 3;
    row = getRow(rowIndex);
    printf("index: %d\n", rowIndex);
    printVector(row);


    return 0;
}
