#include <cstdint>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = INT32_MAX, maxp = 0;

    for (int price : prices) {
        if(price < buy){
            buy = price;
        }


        if (maxp < price - buy)
            maxp = price - buy;
    }

    return maxp;
}


int main(){
    vector<int> nums1(10);
    int ans;
    generateRandomVec(nums1, 0, 100);
    printVector(nums1);
    ans = maxProfit(nums1);
    cout << "result: " << ans << endl;

    return 0;
}
