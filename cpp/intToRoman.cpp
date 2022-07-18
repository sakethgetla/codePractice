#include <cstdlib>
#include <unordered_map>
#include <vector>
#include<iostream>

using namespace std;

string intToRoman(int num){
    // unordered_map<int, char> m = {{ 1, 'I'}, {5,'V' }, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};

    // Array<int, char> m = {{ 1, 'I'}, {5,'V' }, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    // vector<int> dec = {1, 5, 10, 50, 100, 500, 1000};
    // int dec[7] = {1,4, 5, 10, 50, 100, 500, 1000};
    int dec[13] = {1,4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    // char rom[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    string rom[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int curr = 12;
    string out;

    // for (int i = 0; i < 7; i++){
    //    cout << rom[i] << ' ' << dec[i] << endl;
    // }



    // while(num >= 1 && curr >= 0){
    while(num >= 1 ){
        // if (dec[curr] % num > 0){
        if (dec[curr] <= num ){
           // out.append(rom[curr]) ;
           // out.append("eist") ;
            // cout << num << ' '<< dec[curr] << ' ' << dec[curr]%num<< endl;
            out += rom[curr];
            num -= dec[curr];

            // if (num / dec[curr] >= 4){
            //     out += rom[curr];
            //     out += rom[curr+1];
            //     num -= 4*dec[curr];
            // }else {
            //     out += rom[curr];
            //     num -= dec[curr];
            // }
        } else {
            // num ++;
            curr --;
        }

    }

    // for (const auto a : m){
    //     cout << a.first << endl;
    // }
    // for(int i : m.begin()){
    // for(const auto i : m){
    //     // cout << i.first << ", " << i.second  << endl;
    //     cout << i.first << ", " << i.second  << endl;
    // }


    // while ()

    return out;
}

int main(){
    int a = 1994;
    cout << a << "<<<<<<<<<<<<<<<<<<" << endl;
    cout << intToRoman(a) << endl;
    cout << "<<<<<<<<<<<<<<<<<<" << endl;
    a = 58;
    cout << a << "<<<<<<<<<<<<<<<<<<" << endl;
    cout << intToRoman(a) << endl;
    cout << "<<<<<<<<<<<<<<<<<<" << endl;
    return 0;
}
