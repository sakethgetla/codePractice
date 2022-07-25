#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;


template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << "->" ;
    }
    cout << endl;
}

// long int divideTwoIntPos(long int dividend, long int divisor){
//     if (dividend >= divisor){
//         dividend -= divisor;
//         return 1 + divideTwoIntPos(dividend, divisor);
//     }
//     return 0;
// }


// int divideTwoInt(int dividend, int divisor){
//     vector<long int> multiples ;
//     vector<long int> factors ;
//     int sign = 0;

//     if(dividend == 0){
//         return 0;
//     }

//     long int newDividend ;

//     if(dividend < 0){
//         newDividend = ((long int) dividend -1) ^ (-1);
//         // newDividend = -dividend;
//         sign ++;
//     } else {
//         newDividend = dividend;
//     }
//     if( divisor < 0 ) {
//         multiples.push_back(((long int) divisor -1) ^ (-1));
//         sign ++;
//     } else {
//         multiples.push_back(divisor);
//     }

//     factors.push_back(1);
//     cout << newDividend << " / " << multiples.front() << " = " << endl;
//     // if((newDividend > 0) != (divisor > 0)){
//     // }

//     long int num = 0;

//     // num = divideTwoIntPos(newDividend, multiples.front());

//     while (newDividend >= multiples[0]){
//         if (newDividend > multiples.back()){
//             multiples.push_back(multiples.back()+multiples.back());
//             factors.push_back(factors.back()+factors.back());
//         }

//         // find the largest multiple smaller than dividend
//         int curr = multiples.size()-1;
//         while (multiples[curr] > newDividend) {
//             curr --;
//         }

//         // printVector(multiples);
//         cout << newDividend << " - " << multiples[curr] << ", " << curr << ", " << num << endl;
//         newDividend -= multiples[curr];
//         // num += curr^2;
//         num += factors[curr];
//     }

//     return (sign == 0 || sign == 2) ? (num > INT32_MAX)? INT32_MAX: num : (-num < INT32_MIN)? INT32_MIN: -num;
// }


int divideTwoInt(int dividend, int divisor){
    long tot = 0;
    long a = dividend, b = divisor;

    if (dividend == 0 ){
        return 0;
    }

    if(dividend == INT32_MIN && divisor == -1)
        return INT32_MAX;


    // if ((dividend < 0) == (divisor < 0)) {
    // }


    if (a < 0) {
        // dividend = ( dividend ^ -1 ) +1;
        a = (a ^ -1) +1;
    }

    if (divisor < 0) {
        b = ( b ^ -1 ) +1;
    }

    // while(dividend >= divisor){
    while(a - b >= 0){
        // unsigned int num = divisor, factor = 1;
        long factor = 1;
        long num = b;
        // while (dividend >= num << 1) {
        while ( a - ( num << 1) >= 0) {
            num = num << 1;
            factor = factor << 1;
            // factor += factor;
        // cout << dividend << ", " << num << ", " << factor << endl;
        }
        // cout << a << ", "<< b << ", " << num << ", " << factor << endl;
        // dividend -= num;
        a -= num;
        tot += factor;
    }
    // cout << a << ", " << tot  << endl;
    return (dividend < 0) == (divisor < 0) ? tot: -tot;
}

int main(){
    int dividend = 10;
    int divisor = 3;
    // divideTwoInt(dividend, divisor);
    long int ans;

    ans = divideTwoInt(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << ans << endl;


    dividend = 17;
    divisor = 3;
    ans = divideTwoInt(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << ans << endl;
    // // cout << dividend << " / " << divisor << " = " << divideTwoInt(dividend, divisor) << endl;


    dividend = 7;
    divisor = -3;
    ans = divideTwoInt(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << ans << endl;
    // cout << dividend << " / " << divisor << " = " << divideTwoInt(dividend, divisor) << endl;

    dividend = -1;
    divisor = 1;
    ans = divideTwoInt(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << ans << endl;

    dividend = 2147483647;
    divisor = 1;
    ans = divideTwoInt(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << ans << endl;

    dividend = -2147483648;
    divisor = 1;
    ans = divideTwoInt(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << ans << endl;

    // dividend = -2147483648;
    // divisor = -1;
    // ans = divideTwoInt(dividend, divisor);
    // cout << dividend << " / " << divisor << " = " << ans << endl;


    return 0;
}
