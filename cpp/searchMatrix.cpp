#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;


template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << "->" ;
    }
    cout << endl;
}

void print2dVec(vector<vector<int>> vec){
    for (vector<int> v : vec){
        printVector(v);
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int currx= 0, curry= matrix.size()-1;
    while(currx <= matrix[0].size()-1 && curry >= 0 ){
        if (matrix[curry][currx] == target) {
            return true;
        } else if (matrix[curry][currx] > target) {
            curry--;
        } else {
            currx++;
        }
    }
    return false;
}


// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     // brute force
//     for(vector<int> row: matrix){
//         for(int val: row){
//             if(val == target){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 15;
    cout << target << endl;
    print2dVec(matrix);
    bool ans = searchMatrix(matrix, target);
    cout << ans << endl;
    assert( ans == true );


    matrix = {{-1, 3}};
    target = 3;
    cout << target << endl;
    print2dVec(matrix);
    ans = searchMatrix(matrix, target);
    cout << ans << endl;
    assert( ans == true );

    matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    target = 20;
    cout << target << endl;
    print2dVec(matrix);
    ans = searchMatrix(matrix, target);
    cout << ans << endl;
    assert( ans == false );

    return 0;
}
