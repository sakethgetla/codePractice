#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << ',' ;
    }
    cout << endl;
}

vector < string > letterCombinations(string digits){
    unordered_map<int, string> m = {{2, "abc"}, {3, "def"},{4, "ghi"}, {5, "jkl"},{6, "mno"},{7, "pqrs"},{8, "tuv"},{9, "wxyz"}};
    // vector<string> old = {""};
    vector<string> old = {""};
    // vector<string> next = {""};
    vector<string> next ;

    if(digits.empty()){
        return {};
    }

    for(char c : digits){
        cout << m[c-'0'] << endl;
        // printVector(old);
        for(char d : m[c-'0']){
            for (string o : old){
                next.push_back(o+d);
            }
        }
        old = next;
        next = {};
    }

    return old;
}



int main(){

    string digits = "23";
    // digits = "2";
    digits = "";

    printVector(letterCombinations(digits));
    // cout << letterCombinations(digits) << endl;

    return 0;
}
