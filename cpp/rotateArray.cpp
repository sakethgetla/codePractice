#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

// void rotateArray(vector<int>& nums, int k) {
//     // vector<int> vec (nums.size());

//     k = k%nums.size();

//     vector<int> vec ;

//     for (int i = nums.size()-k; i < nums.size(); i++) {
//         vec.push_back(nums[i]);
//     }

//     for (int i = 0; i < nums.size()-k; i++) {
//         vec.push_back(nums[i]);
//     }

//     nums = vec;
// }


void rotateArray(vector<int>& nums, int k) {
    k = k%nums.size();
    int temp = 0;
    for (int j = 0; j < nums.size()-k && k; ) {
        for (int i = nums.size()-k; i < nums.size() && j < nums.size()-k; i++, j++) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            // cout << j << endl;
        }
    }
}

int main(){
    vector<int> nums = generateRandomVec(8, 0, 100);
    int k = 0;
    printVector(nums);
    rotateArray(nums, k);
    printVector(nums);
    return 0;
}
