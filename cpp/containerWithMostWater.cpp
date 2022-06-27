#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int maxArea(vector<int>& height) {
    int high = height.size()-1;
    int low = 0;
    int largestArea = 0;
    int area = 0;
    int temp = 0;

    while(high > low){
        // area = min(height[high], height[low]) * abs(high - low);
        area = min(height[high], height[low]) * (high - low);
        if( area > largestArea){
            largestArea = area;
        }


        if (height[low] > height[high]){
           high--;
        } else {
           low++;
        }

        // // find if high or low is bigger
        // if (height[low] > height[high]){
        //    temp = high;
        //    high--;
        //    // find the next high
        //    while(height[high] < height[temp] && high > low){
        //        high--;
        //    }

        // } else {
        //    temp = low;
        //    low++;
        //    // find the next high
        //    while(height[low] < height[temp] && high > low){
        //        low++;
        //    }

        // }

    }

    return largestArea;
}

int main(){
    vector<int> a {1,8,6,2,5,4,8,3,7};
    cout << maxArea(a) << endl;
    a= {1,1};
    cout << maxArea(a) << endl;
    return 0;
}
