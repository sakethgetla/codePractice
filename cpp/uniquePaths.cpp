#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << "->" ;
    }
    cout << endl;
}


// int uniquePaths(unordered_map<int[2], int> hmap, int m, int n){

int uniquePaths(unordered_map<int, int> *hmap, int m, int n){
    if (m == 1 || n == 1){
        return 1;
    } else {
        int count = 0;

        // if (hmap.find({m, n-1}) == hmap.end()) {
        if (hmap->find(( m*100 ) +n-1) == hmap->end()) {
            // hmap[( m*100 ) +n-1] = uniquePaths(hmap, m, n-1);
            hmap->insert({(m*100 ) +n-1, uniquePaths(hmap, m, n-1)});
        }
        count += hmap->at( ( m*100 ) +n-1 );

        // if (hmap.find({m-1, n}) == hmap.end()) {
        if (hmap->find(( ( m-1 )*100 ) +n) == hmap->end()) {
            // hmap[( ( m-1 )*100 ) +n] = uniquePaths(hmap, m-1, n);
            hmap->insert({( ( m-1 )*100 ) +n, uniquePaths(hmap, m-1, n)});
        }
        count += hmap->at(( ( m-1 )*100 ) +n);

        return count;
    }
    return 0;
}

int uniquePaths(int m, int n){
    unordered_map<int, int> a;
    unordered_map<int, int> *hmap = &a;
    // unordered_map<int[2], int> hmap;

    return  uniquePaths(hmap, m, n);
}

// int uniquePaths(int m, int n){
//     if (m == 1 || n == 1){
//         return 1;
//     } else {
//         int count = 0;
//         count += uniquePaths(m-1, n);
//         count += uniquePaths(m, n-1);
//         // for (int i = 1; i < n; i++) {
//         //     count += uniquePaths(m, i);
//         // }
//         // for (int i = 1; i < m; i++) {
//         //     count += uniquePaths(i, n);
//         // }
//         // return 2 + count;
//         return count;
//     }
//     return 0;
// }

int main(){
    int m = 2, n = 2;
    int ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 2);

    m = 3, n = 2;
    ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 3);
    assert(uniquePaths(m, n) == uniquePaths(n, m));
    // cout << m << ", " << n << ", " << uniquePaths(m, n) << endl;

    m = 3, n = 3;
    ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 6);
    assert(uniquePaths(m, n) == uniquePaths(n, m));
    // cout << m << ", " << n << ", " << uniquePaths(m, n) << endl;

    m = 5, n = 5;
    ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 70);
    assert(uniquePaths(m, n) == uniquePaths(n, m));
    // cout << m << ", " << n << ", " << uniquePaths(m, n) << endl;

    m = 1, n = 1;
    ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 1);
    assert(uniquePaths(m, n) == uniquePaths(n, m));
    // cout << m << ", " << n << ", " << uniquePaths(m, n) << endl;

    m = 1, n = 5;
    ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 1);
    assert(uniquePaths(m, n) == uniquePaths(n, m));
    // cout << m << ", " << n << ", " << uniquePaths(m, n) << endl;

    m = 3, n = 1;
    ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 1);
    assert(uniquePaths(m, n) == uniquePaths(n, m));
    // cout << m << ", " << n << ", " << uniquePaths(m, n) << endl;

    m = 3, n = 7;
    ans = uniquePaths(m, n);
    cout << m << ", " << n << ", " << ans  << endl;
    assert(ans == 28);
    assert(uniquePaths(m, n) == uniquePaths(n, m));
    // cout << m << ", " << n << ", " << uniquePaths(m, n) << endl;



    m = 51, n = 9;
    ans = uniquePaths(m, n);
    int ans1 = uniquePaths(n, m);
    assert(ans == ans1);
    cout << ans1 << ", " << ans1 << endl;

    // ans = uniquePaths(m, n);
    // cout << m << ", " << n << ", " << ans  << endl;
    // assert(ans == 28);
    return 0;
}
