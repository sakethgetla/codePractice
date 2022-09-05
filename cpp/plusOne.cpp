#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

vector<int> plusOne(vector<int>& digits){
    int i = digits.size()-1;
    while (i >= 0 && digits[i] == 9) {
        digits[i] = 0;
        i--;
    }
    if (i < 0) {
        // vector<int> a ;
        // a.push_back(1);
        // a.insert(a.end(), digits.begin(), digits.end());
        vector<int> a(digits.size()+1, 0);
        a[0] = 1;
        return a;
    } else {
        digits[i] ++;
        return digits;
    }
}

int main(){
    vector<int> vec = generateRandomVec(6, 0, 10);
    printVector(vec);
    vec = plusOne(vec);
    printVector(vec);

    vec = generateRandomVec(6, 9, 10);
    printVector(vec);
    vec = plusOne(vec);
    printVector(vec);

    return 0;
}
