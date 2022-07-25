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

// vector<int> searchRange(vector<int>& nums, int target) {

//     int low = 0, high = nums.size()-1, mid;

//     while (high >= low) {
//         mid = (high + low)/2;
//         if (nums[mid] == target ) {
//             // found
//             while(mid > 0 && nums[mid-1] == target){
//                 mid --;
//             }
//             low = mid;

//             while(mid < nums.size()-1 && nums[mid+1] == target){
//                 mid ++;
//             }
//             high = mid;

//             // cout << "here" << endl;

//             return {low, high};
//         } else if (nums[mid] > target) {
//             high = mid-1;
//         } else {
//             low = mid+1;
//         }
//     }

//     // return {mid, mid};
//         return {-1, -1};
//     // if (nums.size() != 1) {
//     //     return {-1, -1};
//     // } else if (nums[0] == target) {
//     //     return {0, 0};
//     // } else {
//     //     return  {-1, -1};
//     // }
//}
//

vector<int> searchRange(vector<int>& nums, int target) {

    int low = 0, high = nums.size()-1, mid = -1;
    double t = target-0.5;

    while (high >= low) {
        mid = (high + low)/2;
        if (nums[mid] == t ) {
            assert(false);
            high = low+1;
            // return {low, high};
        } else if (nums[mid] > t) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    int start = mid;
    if (start < nums.size()-1 && nums[start] != target) {
        start ++;
    }

            // cout << "here" << endl;

    // cout << t << endl;

    t = target+0.5;
    high = nums.size()-1;
            // assert(false);

    while (high >= low) {
        mid = (high + low)/2;
        if (nums[mid] == t) {
            high = low+1;
            assert(false);

            // return {low, high};
        } else if (nums[mid] > t) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    // cout << t << endl;
            // cout << "here" << endl;

    int end = mid;
    if (end > 0 && nums[end] != target) {
            // cout << "here" << endl;
        end --;
    }

            // cout << start << " here" << endl;
    // cout << nums[ start ] << ", " << nums[ end ] << endl;
    if (start > 0 && nums[start] == target)
        return {start, end};
    else
        return {-1, -1};
}

int main(){
  //vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    vector<int> nums = {5,7,7,8,8,8,8,8,9}, ans;
    vector<int> exp = {3, 7};
    int target = 8;

    cout << target << ": ";
    printVector(nums);
    ans = searchRange(nums, target);
    printVector(ans);
    exp = {3, 7};
    assert(ans == exp && "failed");
    // assert(ans == vector<int>{3,7});

    nums = {};
    target = 9;
    cout << target << ": ";
    printVector(nums);
    ans = searchRange(nums, target);
    printVector(ans);
    exp = {-1, -1};
    assert(ans == exp && "failed");

    printVector(searchRange(nums, target));

 //nums = {0,1,2,3,4,5,6,7,8,9};
    nums = {5};
    target = 8;
    cout << target << ": ";
    printVector(nums);
    ans = searchRange(nums, target);
    printVector(ans);
    // printVector(searchRange(nums, target));

  //nums = {0,1,2,3,4,5,6,7,8,9};
    nums = {5};
    target = 5;
    cout << target << ": ";
    printVector(nums);
    ans = searchRange(nums, target);
    printVector(ans);
    exp = {0, 01};
    assert(ans == exp && "failed");
    // printVector(searchRange(nums, target));

  //nums = {0,1,2,3,4,5,6,7,8,9};
    nums = {0,0,5,5,5,5};
    target = 5;
    cout << target << ": ";
    printVector(nums);
    ans = searchRange(nums, target);
    printVector(ans);
    // printVector(searchRange(nums, target));

  //nums = {0,1,2,3,4,5,6,7,8,9};
    nums = {5,7,7,8,8,9};
    target = 9;
    cout << target << ": ";
    printVector(nums);
    ans = searchRange(nums, target);
    printVector(ans);
    // printVector(searchRange(nums, target));

    return 0;
}
