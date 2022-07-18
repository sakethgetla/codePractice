#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec, int len){
    // for (int v : vec){
    for (int v = 0 ; v < len ; v++){
        cout << vec[v] << ' ' ;
    }
    cout << endl;
}

int removeElement(vector<int> &nums, int val){
    int curr = 0;
    int temp;
    int last = nums.size() -1;
    while (curr <= last){
        if (nums[curr] == val){
            // swap curr and last
            nums[curr] = nums[last];
            last --;
        } else {
            curr ++;
        }
    }

    // for (int i = 0; i < len; i ++) {

    // }

    return last+1;
}

int main(){

    vector<int> nums = {1,2,3,4,5,6,3,3,3,4,1,2,3,5};
    int val = 3;

    printVector(nums, nums.size());
    int len = removeElement(nums, val) ;

    // cout << removeElement(nums, val) << endl;

    printVector(nums, len);
    return 0;
}
