#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"


using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int count = 0;
    // vector<int> currs(matrix.size(), 0);
    vector<int*> currs;

    for (int i = 0; i < matrix.size(); i++) {
        // currs[i] = &matrix[i][0];
        currs.push_back(&matrix[i][0]);
    }

    int min = 0;
    while(count < k){

        // find smallest.
        for (int i = 0; i < currs.size(); i++) {
            if (currs[min] > currs[i] && currs[min]) {
                min = i;
            }
        }

        count ++;
    }
    cout << *currs[0] << endl;
    return 0;

}

int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    print2dVec(matrix);
    kthSmallest(matrix, 3);
    // matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    return 0;
}
