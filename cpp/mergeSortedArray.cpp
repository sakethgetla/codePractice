#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

}

int main(){

    vector<int> nums1(12, 0) = {-2,3,14,35};
    // nums1 = ;
    vector<int> nums2 = {-2,1,4,11,21,21,35,44};
    int m = 12, n = 8;
    printVector(nums1);
    printVector(nums2);

    merge(nums1, m, nums2, n);

    printVector(nums1);

    return 0;
}
