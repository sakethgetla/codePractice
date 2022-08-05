#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;

 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     vector<int> *smallerNums = (nums1.size() < nums2.size()) ? &nums1 : &nums2;
     vector<int> *biggerNums = (nums1.size() >= nums2.size()) ? &nums1 : &nums2;
     vector<int> intersec;
     int count = smallerNums->size();
     unordered_map<int, int> freq;
     for (int num  : *smallerNums) {
         if (freq.find(num) == freq.end()  ) {
            freq[num] = 1;
         } else {
             freq[num] ++;
         }
     }

     for (int num  : *biggerNums) {
         if (freq.find(num) != freq.end() && freq[num] > 0) {
             freq[num]--;
             intersec.push_back(num);
             count--;
         }

         if(count == 0)
             return intersec;
     }
     return intersec;
 }

int main(){

    vector<int> nums1(10);
    vector<int> nums2(2);

    generateRandomVec(nums1, 0, 10);
    generateRandomVec(nums2, 1, 2);
    printVector(nums1);
    printVector(nums2);
    printVector(intersect(nums1, nums2));


    return 0;
}
