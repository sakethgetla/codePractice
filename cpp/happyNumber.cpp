#include <cmath>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <unordered_set>
#include "helperFunctions.cpp"

using namespace std;

bool isHappy(int n) {
    unordered_set<int> seen;
    int newn = 0;

    while (seen.find(n) == seen.end()) {
        seen.insert(n);
        while ( n > 0 ){
            newn += pow(n%10, 2);
            n = n/10;
        }
        n = newn;
        newn = 0;
    }

    return seen.find(1) != seen.end();
}

void printSet(unordered_set<int> s){

}

int main(){
    // cout << (1%10) << endl;
    // cout << (8%10) << endl;
    // cout << (8/10) << endl;
    // cout << (9/10) << endl;



    int n = 19;
    bool ans = isHappy(n);
    cout << n << ", " << ans << endl;

    n = 1;
    ans = isHappy(n);
    cout << n << ", " << ans << endl;

    n = 2;
    ans = isHappy(n);
    cout << n << ", " << ans << endl;

    // unordered_set<int> seen;

    // cout <<  (seen.find(n) == seen.end()) << endl;
    // seen.insert(n);
    // seen.insert(n+1);
    // cout <<  (seen.find(n) == seen.end()) << endl;
    // seen.insert(1);
    // cout <<  (seen.find(1) == seen.end()) << endl;
    // seen.insert(1);
    // seen.insert(1);

    // cout <<  (seen.find(n) == seen.end()) << endl;

    return 0;
}
