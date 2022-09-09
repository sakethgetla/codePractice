#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <unordered_map>
#include <cassert>
#include <utility>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

// int climbStaris(int two, int one){
// }

int climbStaris(int n){
    int ones=1, temp, twos=0;
    for (int i = 1; i < n; i++) {
        temp = twos;
        twos = ones;
        ones += temp;
    }
    return ones + twos;
}

// int climbStaris(int n){
//     vector<pair<int, int>> com;
//     // int i = 1;
//     com.push_back({1, 0});
//     int temp;

//     for (int i = 1; i < n ; i *= 2) {
//         // temp = com.back().second;
//         com.push_back({com.back().first, com})

//     }

// }


int main(){
    int n ;
    int ans ;
    n = 2;
    ans = climbStaris(n);
    printf("n = %d, %d\n", n, ans);

    n = 3;
    ans = climbStaris(n);
    printf("n = %d, %d\n", n, ans);

    n = 4;
    ans = climbStaris(n);
    printf("n = %d, %d\n", n, ans);

    n = 30;
    ans = climbStaris(n);
    printf("n = %d, %d\n", n, ans);

    return 0;
}
