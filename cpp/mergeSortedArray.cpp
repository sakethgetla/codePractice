#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

//     vector<int> temp = nums1;
//     int a = 0, b = 0;

//     for (int i = 0; i < nums1.size(); i++) {
//         if (b >= n || (a < m && temp[a] < nums2[b])) {
//             nums1[i] = temp[a];
//             a++;
//         } else {
//             nums1[i] = nums2[b];
//             b++;
//         }
//     }

// }

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int a = m-1, b = n-1;
    for (int i = nums1.size()-1; i >= 0; i--) {
        if (b < 0 || (a >= 0 && nums1[a] > nums2[b])) {
            nums1[i] = nums1[a];
            a--;
        } else {
            nums1[i] = nums2[b];
            b--;
        }
    }

}
int main(){

    vector<int> temp(6, 0);
    vector<int> nums1(6);
    // nums1 = ;
    vector<int> nums2(6);

    generateSortedVec(nums1, -10, 10);
    generateSortedVec(nums2, -10, 10);

    nums1.insert(nums1.end(), temp.begin(), temp.end());

    int m = 12, n = 6;
    printVector(nums1);
    printVector(nums2);

    merge(nums1, m, nums2, n);
    printVector(nums1);


    nums1 = {1};
    m=1;
    nums2 = {};
    n=0;
    printVector(nums1);
    printVector(nums2);
    merge(nums1, m, nums2, n);
    printVector(nums1);

    nums1 = {0};
    m=0;
    nums2 = {1};
    n=1;
    printVector(nums1);
    printVector(nums2);
    merge(nums1, m, nums2, n);
    printVector(nums1);
    assert(nums1 == nums2);

    return 0;
}
