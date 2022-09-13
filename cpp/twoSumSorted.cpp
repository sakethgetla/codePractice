#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size()-1;

    while (i < j) {
        // cout << numbers[i] + numbers[j] << " " <<  target << endl;
        if (numbers[i] + numbers[j] == target) {
            return {i+1, j+1};
        } else if (numbers[i] + numbers[j] > target) {
            j--;
        } else if (numbers[i] + numbers[j] < target) {
            i++;
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> nums;
    vector<int> ans;
    int target;

    nums= {2, 3, 4};
    target = 6;
    printVector(nums);
    cout << target << endl;
    ans = twoSum(nums, target);
    printVector(ans);

    nums= {-1, 0};
    target = -1;
    printVector(nums);
    cout << target << endl;
    ans = twoSum(nums, target);
    printVector(ans);

    nums= {2,7,11,15};
    target = 9;
    printVector(nums);
    cout << target << endl;
    ans = twoSum(nums, target);
    printVector(ans);
    return 0;
}
