#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> occurred;
    for (int x : arr) {
        if(occurred.find(x) == occurred.end()){
            occurred[x] = 1;
        } else {
            occurred[x] += 1;
        }
    }

    unordered_map<int, bool> uniques;

    for( pair<int, int> u : occurred ){
        if (uniques.find(u.second) == uniques.end()){
            uniques[u.second] = true;
        } else {
            return false;
        }

    }

    // unordered_map<int, int> uniques;

    // for (int x : arr) {
    //     if (uniques.find( occurred[x] ) == uniques.end() ) {
    //         uniques[occurred[x]] = x;
    //     } else if (uniques[occurred[x]] != x){
    //         return false;
    //     }
    // }

    return true;
}

int main(){
    vector<int> v = {1,2,2,1,1,3};
    bool ans = uniqueOccurrences(v);
    printVector(v);
    cout << ans << endl;

    v = {1, 2};
    ans = uniqueOccurrences(v);
    printVector(v);
    cout << ans << endl;

    v = {-3,0,1,-3,1,1,1,-3,10,0};
    ans = uniqueOccurrences(v);
    printVector(v);
    cout << ans << endl;

    return 0;
}
