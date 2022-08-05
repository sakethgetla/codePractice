#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (m*n)-1, mid;

    while (low <= high) {
        mid = (high + low)/2;
        if (matrix[mid/n][mid%n] == target) {
            return true;
        } else if (matrix[mid/n][mid%n] < target) {
            low = mid +1;
        } else {
            high = mid-1;
        }
    }

    return false;
}

int main(){
    int m = 5, n = 4, target = -14;
    vector<int> nums(m*n);

    generateSortedVec(nums, -100, 100);
    printVector(nums);

    vector<vector<int>> matrix;

    matrix = vecToMatrix(nums, m, n);
    print2dVec(matrix);
    cout << "target: " << target << endl;
    cout << "found" << searchMatrix(matrix, target) << endl;


    target = 5;
    cout << "target: " << target << endl;
    cout << "found: " << searchMatrix(matrix, target) << endl;

    target = 101;
    cout << "target: " << target << endl;
    cout << "found: " << searchMatrix(matrix, target) << endl;
    // searchMatrix(matrix, target)

    return 0;
}
