#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int s2 = nums[0], s1 = max(nums[0], nums[1]), temp;
    for (int i = 2; i < nums.size() ; i++){
        temp = s1;
        s1 = max(s2+ nums[i], s1-nums[i-1]+nums[i]);
        s2 = temp;
        // if (s2 + nums[i] > s1 - nums[i-1] + nums[i]) {
        //     temp = max(s1, s2);
        //     s1 = s2+nums[i];
        //     s2 = temp;

        // } else {
        //     // temp = s1;
        //     temp = max(s1, s2);
        //     s1 = s1 - nums[i-1] + nums[i];
        //     s2 = temp;
        // }
    }

    // return max(nums.size()-2, nums.size()-1);
    return max(s1, s2);
}

int main(){
    vector<int> nums ;
    int ans ;

    nums = {2, 7, 9, 3, 1};
    ans = rob(nums);
    printVector(nums);
    cout << "ans: " << ans << endl;

    nums = {1,2,3,1};
    ans = rob(nums);
    printVector(nums);
    cout << "ans: " << ans << endl;

    nums = {1,9,2,3,9,1};
    ans = rob(nums);
    printVector(nums);
    cout << "ans: " << ans << endl;

    nums = {9,2,3,9};
    ans = rob(nums);
    printVector(nums);
    cout << "ans: " << ans << endl;
    return 0;
}
