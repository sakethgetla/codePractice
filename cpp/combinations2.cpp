#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

vector<vector<int>> combinations;

void helper(vector<int> &curr, int start, int k, int n){
    if (curr.size() == k ) {
        combinations.push_back(curr);
    }

    for (int i = start; i <= n; i++) {
        curr.push_back(i);
        helper(curr,  i+1 , k, n);
        curr.pop_back();
    }

}

vector<vector<int>> combine(int n, int k) {
    vector<int> a;
    helper(a, 1, k, n);
    return combinations;
}

int main(){
    int n = 1, k = 1;
    vector<vector<int>> a = combine(n, k);
    print2dVec(a);
    return 0;
}
