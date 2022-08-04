#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

int searchInsert(vector<int>& nums, int target) {
   int low = 0, high = nums.size()-1, mid;
   while (low <= high) {
       mid = (high + low)/2;
       if (nums[mid] == target) {
           return mid;
       } else if (nums[mid] > target) {
           high = mid-1;
       } else {
           low = mid+1;
       }
   }
   // cout << mid << endl;
   return (nums[mid] > target) ? mid : mid+1;
}

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 5;
    int ans = searchInsert(nums, target);
    printVector(nums);
    cout <<  "target: "  << target << ", " << "ans: "<< ans << endl;
    assert(ans == 2);

    nums = {1,3,5,6};
    target = 4;
    ans = searchInsert(nums, target);
    printVector(nums);
    cout <<  "target: "  << target << ", " << "ans: "<< ans << endl;
    assert(ans == 2);

    nums = {1,3,5,6};
    target = 2;
    ans = searchInsert(nums, target);
    printVector(nums);
    cout <<  "target: "  << target << ", " << "ans: "<< ans << endl;
    assert(ans == 1);

    return 0;
}
