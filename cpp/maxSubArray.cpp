#include <cstdint>
#include <cstdlib>
#include <type_traits>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

// int maxSubArray(vector<int>& nums) {
//     int maxSum = INT32_MIN, sum = 0;
//     // for (int i = 0 ; i < nums.size() ; i++) {
//     //     num = nums[i];
//     for (int num : nums) {
//         if (sum > 0 && sum + num > 0) {
//             sum += num;
//         } else {
//             sum = num;
//             // sum = 0;
//         }

//         if(sum > maxSum)
//             maxSum = sum;
//         else if (num > maxSum)
//             maxSum = num;
//     }

//     return maxSum;
// }

int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
}

int main(){
    assert(INT32_MIN < -1);
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(nums);
    printVector(nums);
    cout <<  "ans: "<< ans << endl;
    assert(ans == 6);

    nums = {5,4,-1,7,8};
    ans = maxSubArray(nums);
    printVector(nums);
    cout <<  "ans: "<< ans << endl;
    assert(ans == 23);

    nums = {-1};
    ans = maxSubArray(nums);
    printVector(nums);
    cout <<  "ans: "<< ans << endl;
    assert(ans == -1);

    nums = {1};
    ans = maxSubArray(nums);
    printVector(nums);
    cout <<  "ans: "<< ans << endl;
    assert(ans == 1);

    return 0;
}
