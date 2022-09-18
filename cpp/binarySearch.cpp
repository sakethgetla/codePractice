#include <algorithm>
#include <cstdlib>
#include<iostream>
#include <stdexcept>
#include<vector>
#include "helperFunctions.cpp"

using namespace std;


void merge(int* array, int low, int mid, int high){
    // H
}

void mergeSort(int* array, int low, int high){
    int length = high - low;
    if (length == 1){
        // return array;
        return;
    } else if (length == 2){
        if ( array[0] < array[1] ){
            return;
            // return array ;
        } else {
            //swap
            int temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            // return array;
        }
    } else if (length > 2){
        int mid = length/2;
        // int* front = mergeSort(array,low,  mid);
        // int* back = mergeSort(array, mid, high);
        mergeSort(array,low,  mid);
        mergeSort(array, mid, high);
        merge(array, low, mid, high);
        // return merge(array, low, mid, high);
        // return mergeSort(array, mid)
    } else {
        cout << "error" << endl;
        // return NULL;
    }
}

void printArray(int* array, int length){
    for( int a = 0 ; a < length ; a++  ){

        cout << array[a] << ", ";
    }
    cout << endl;
}


int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1, mid;

    while (low <= high) {
        mid = (low + high)/2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}


// vector<int> vec ;
int target;

bool isBadVersion(int n){
    return (n >= target);
}

int firstBadVersion(int n) {
    int low = 0, high = n-1, mid;

    while (low < high) {
        // mid = (low+high)/2;
        mid = ((high-low)/2)+low;
        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    return high;
}

int searchInsert(vector<int>& nums, int target) {
   int l = 0, h = nums.size()-1, mid;
   while (l < h) {
       mid = (l+h)/2;
       if (nums[mid] == target) {
           return mid;
       } else if (nums[mid] < target) {
           l = mid+1;
       } else {
           h = mid;
       }
   }
   return h;
}


int main(){

    // int* i = a;
    // vector<int> a = {1,3,4};
    // mergeSort(a, 3);

    vector<int> vec ;
    // int target;
    int ans;

    vec = generateSortedVec(20, 0, 10);
    target = 5;
    // ans = search(vec, target);
    ans = searchInsert(vec, target);
    printVector(vec);
    cout << "target: " << target << ", ans: " << ans << endl;

    // vec = generateSortedVec(20, 0, 100);
    vec = generateSortedVec(20, 0, 20);
    target = 1;
    ans = searchInsert(vec, target);
    printVector(vec);
    cout << "target: " << target << ", ans: " << ans << endl;


    vec = generateSortedVec(20, 0, 50);
    target = 9;
    ans = searchInsert(vec, target);
    printVector(vec);
    cout << "target: " << target << ", ans: " << ans << endl;
    return 0;
}
