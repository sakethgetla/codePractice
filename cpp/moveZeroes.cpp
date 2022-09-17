#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;


// void printVector(vector<int> vec){
//     for (int v : vec){
//         cout << v << ' ' ;
//     }
//     cout << endl;
// }

// void moveZeroes(vector<int> &nums){
//     int curr = 0;
//     int high = 0;
//     while(curr < nums.size()){
//         if(high < nums.size() ) {
//             if(nums[high] != 0) {
//                 nums[curr] = nums[high];
//                 curr ++;
//                 // nums[curr] = nums[]
//             }
//             high ++;
//         } else {
//             nums[curr] = 0;
//             curr ++;

//         }
//     }
// }


void moveZeroes(vector<int> &nums){
    int curr=0, temp;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != 0 && nums[curr] == 0) {
            swap(nums[i], nums[curr]);
        }
        // if(nums[curr] != 0){
        if(nums[curr]){
           curr++;
        }
    }
}

int main(){
    vector<int> nums = {1,0, 2,3,0, 4,5,6,0,0,0,3,3,3,4,1,2,3,5};
    printVector(nums);
    moveZeroes(nums);
    printVector(nums);

    nums = {-1,0, -2,-3,0, 4,5,6,0,0,0,3,3,3,4,1,2,3,5};
    printVector(nums);
    moveZeroes(nums);
    printVector(nums);
    return 0;
}
