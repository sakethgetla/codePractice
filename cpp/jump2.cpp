#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

// int jump(vector<int>& nums) {
//     int currJumps = 1, lastJump = 0;
//     if (nums.size() == 1) {
//         return 0;
//     }
//     for (int i = 1; i < nums.size(); i++) {
//         // if (nums.size()-1 <= lastJump + nums[ lastJump ]) {
//         //     return currJumps+1;
//         // // } else if (nums[nums[i]+i] + nums[i]+i > nums[nums[ lastJump ] + lastJump] + nums[ lastJump ] + lastJump) {
//         // } else if ( nums[i]+i > nums[nums[ lastJump ] + lastJump] + nums[ lastJump ] + lastJump ) {
//         if ( nums[i]+i > nums[nums[ lastJump ] + lastJump] + nums[ lastJump ] + lastJump ) {
//             lastJump = i;
//             if (nums.size()-1 <= lastJump + nums[ lastJump ]) {
//                 return currJumps+1;
//             }
//         } else if (i == lastJump + nums[lastJump]) {
//             lastJump = i;
//             printf("jump %d: %d \n", i, nums[i]);
//             if (nums.size()-1 <= lastJump + nums[ lastJump ]) {
//                 return currJumps;
//             }
//             currJumps++;
//         }
//     }
//    return -1;
// }


// int jump(vector<int>& nums) {
//     int curr = 0, numJumps = 0, i = 0;
//     // for (int i = 0; i < nums.size(); i++) {
//     // while (i + nums[i] < nums.size()) {
//     while (i < nums.size()) {
//         curr = i+nums[i];
//         // for (int j = 0 ; j < nums[i] && j + i < nums.max_size() ; j++) {
//         for (int j = i+1 ; j <= i+nums[i] ; j++) {
//             if (curr + nums[curr] < j + nums[j]) {
//                 curr = j;
//             }
//             if (curr+nums[curr] >= nums.size()-1) {
//                 cout << "here" << endl;
//                 return numJumps+1;
//             }
//         }
//         numJumps++;
//         i = i+nums[i];
//         // i ++;
//         printf("jump %d: %d \n", i, nums[i]);
//     }
//     return numJumps;
// }


int jump(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;

    int lastJump = 0, nextJump = 0, jumps = 0;
    for (int i = 0 ; i < nums.size(); i++) {
        if (i == lastJump + nums[lastJump]) {
            lastJump = nextJump;
            jumps++;
            cout << "here" << endl;
        }
        if (i + nums[i] >= nums.size()-1) {
            return jumps+1;
        }
        if (i + nums[i] > nextJump+ nums[nextJump]) {
            nextJump = i;
        }
    }

    return -1;
}


int main(){

    vector<int> nums ;
    int ans ;

    nums = {2,3,1,1,4} ;
    printVector(nums);
    ans = jump(nums);
    cout << "jumps " << ans << endl;

    nums = {2,3,0,1,4} ;
    printVector(nums);
    ans = jump(nums);
    cout << "jumps " << ans << endl;

    nums = {1,2} ;
    printVector(nums);
    ans = jump(nums);
    cout << "jumps " << ans << endl;
    assert(ans == 1);

    nums = {1,2,3} ;
    printVector(nums);
    ans = jump(nums);
    cout << "jumps " << ans << endl;
    assert(ans == 2);

    nums = {0} ;
    printVector(nums);
    ans = jump(nums);
    cout << "jumps " << ans << endl;
    assert(ans == 0);

    nums = {5,4,0,1,3,6,8,0,9,4,9,1,8,7,4,8} ;
    printVector(nums);
    ans = jump(nums);
    cout << "jumps " << ans << endl;
    assert(ans == 3);

    nums = {2,3,1,1,4} ;
    printVector(nums);
    ans = jump(nums);
    cout << "jumps " << ans << endl;
    assert(ans == 2);
    return 0;
}
