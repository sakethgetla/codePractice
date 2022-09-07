#include <climits>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    if (nums.size() == 1) {
        return 1;
    }
    int i = 0, j = 1, check = nums[i], maxSize = 1;
    while (j < nums.size()) {
        if (i == j) {
            j++;
            check = nums[i];
        } else if ((check & nums[j]) == 0) {
            maxSize = max(maxSize, j-i+1);
            check = check | nums[j];
            j++;
        } else {
            check = check ^ nums[i];
            // check -= nums[i];
            i++;
        }

        // maxSize = max(maxSize, currSize);
    }
    return maxSize;

}

int main(){

    vector<int> nums = {1,3,8,48, 10};
    int out = longestNiceSubarray(nums);
    printVector(nums);
    printf("= %d\n", out);
    assert(out == 3);

    nums = {3,1,5,11, 13};
    out = longestNiceSubarray(nums);
    printVector(nums);
    printf("= %d\n", out);
    assert(out == 1);

    nums = {744437702,379056602,145555074,392756761,560864007,934981918,113312475,1090,16384,33,217313281,117883195,978927664};
    out = longestNiceSubarray(nums);
    printVector(nums);
    printf("= %d\n", out);
    assert(out == 3);



    // int a = 2, b = 8;
    // cout << a << ", " << b << ", " << (a&b) << endl;
    // a = 5, b = 49;
    // cout << a << ", " << b << ", " << (a&b) << endl;

    // a = 3, b = 1;
    // cout << a << ", " << b << ", " << (a&b) << endl;

    // a = 40, b = 40;
    // cout << a << ", " << b << ", " << (a&b) << endl;

    // a = INT_MAX, b = INT_MAX;
    // cout << a << ", " << b << ", " << (a&b) << endl;

    // a = INT_MAX-1, b = INT_MAX-1;
    // cout << a << ", " << b << ", " << (a&b) << endl;

    // a = 1, b = 1;
    // cout << a << ", " << b << ", " << (a|b) << endl;

    return 0;
}
