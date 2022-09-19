#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <unordered_set>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

vector<vector<int>> perumutations;


// void helper(vector<int> &curr, vector<int> &nums, int idx){
// void helper(vector<int> &curr, unordered_set<int> s, int size){
void helper(vector<int> &curr, unordered_set<int> s, int size, int rem){
    if (curr.size() == size) {
        perumutations.push_back(curr);
    }

    s.erase(rem);
    for (int num : s) {
        curr.push_back(num);
        helper(curr, s, size, num);
        curr.pop_back();
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> curr;
    unordered_set<int> s;
    for (int num : nums){
        s.insert(num);
    }
    helper(curr, s, s.size(), INT_MIN);
    return perumutations;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> a = permute(nums);
    printVector(nums);
    cout << endl;
    print2dVec(a);


    return 0;
}
