#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] *= nums[i];
    }
    vector<int> sortednums (nums.size());

    int l = 0, r = nums.size()-1;
    for (int i = sortednums.size()-1; i >= 0 ; i--) {
        if (nums[l] > nums[r]) {
            sortednums[i] = nums[l];
            l++;
        } else {
            sortednums[i] = nums[r];
            r--;
        }
    }
    return sortednums;
}


int main(){
    vector<int> vec, ans;

    vec = {1};
    printVector(vec);
    ans = sortedSquares(vec);
    printVector(ans);

    vec = generateSortedVec(20, -10, 10);
    printVector(vec);
    ans = sortedSquares(vec);
    printVector(ans);

    return 0;
}
