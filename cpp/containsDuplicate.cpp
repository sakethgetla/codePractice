#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> found;
    for (int num : nums) {
        if(found.find(num) == found.end())
            found[num] = true;
        else
            return true;
    }

    return false;

}

int main(){
    vector<int> nums = {1,3,5,6,1};
    bool ans = containsDuplicate(nums);
    printVector(nums);
    cout <<  "ans: "<< ans << endl;
    assert(ans == true);

    nums = {1,3,5,6};
    ans = containsDuplicate(nums);
    printVector(nums);
    cout <<  "ans: "<< ans << endl;
    assert(ans == false);

    return 0;
}
