#include <cstdlib>
#include <iostream>
#include <vector>
// #include <unordered_map>

using namespace std;


template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << "->" ;
    }
    cout << endl;
}

int search(vector<int>& nums, int target) {

    int low = 0, high = nums.size()-1, mid;

    if ( nums[low] > nums[high] ){

        while (high > low+1){
            // cout << low << ", " << high << endl;
            mid = (high + low)/2;
            if (nums[mid] < nums[low]) {
                // pivot is in between low and mid
                high = mid;
            } else if(nums[mid] > nums[high]){
                low = mid;
            }
        }
    }
    // cout << low << ", " << high << endl;
    // break will be between low and high;

    // decide wheather to search the after or befroe the pivot
    if (nums[ low ] >= nums[ high ]){

        if (target >= nums[0]){
            high = low;
            low = 0;
        } else {
            low = high;
            high = nums.size()-1;
        }
    }

    if (target == nums[high]){
        return high;
    }else if (target == nums[low]){
        return low;
    }

    while(low+1 < high){
        mid = (high + low)/2;
        if(target == nums[ mid ]){
            return mid;
        } else if(target == nums[ low ]){
            return low;
        } else if(target == nums[ high ]){
            return high;
        } else if(target > nums[mid]){
            low = mid;
        } else if(target < nums[mid]){
            high = mid;
        }
    }

    return -1;
}


int main(){
  //vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    vector<int> nums = {4,5,6,7,8,9,0,1,2,3};
    int target = 0;

    cout << target << ": ";
    printVector(nums);
    cout << search(nums, target)<< endl;

  //nums = {0,1,2,3,4,5,6,7,8,9};
    nums = {3, 5, 1};
    target = 3;
    cout << target << ": ";
    printVector(nums);
    cout << search(nums, target)<< endl;

  //nums = {0,1,2,3,4,5,6,7,8,9};
    nums = {4,5,6,7,0,1,2};
    target = 2;
    cout << target << ": ";
    printVector(nums);
    cout << search(nums, target)<< endl;

  //nums = {0,1,2,3,4,5,6,7,8,9};
    nums = {1};
    target = 1;
    cout << target << ": ";
    printVector(nums);
    cout << search(nums, target)<< endl;


    nums = {1, 3};
    target = 1;
    cout << target << ": ";
    printVector(nums);
    cout << search(nums, target)<< endl;

    return 0;
}
