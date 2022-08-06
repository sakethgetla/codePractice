#include <climits>
#include <cstdint>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include "helperFunctions.h"

using namespace std;

int firstUniqChar(string s) {
    // int cmap[26] = {-1};
    int cmap[26] = {0};
    // printArray(cmap, 26);
    for (int i = 0; i < s.length(); i++) {
        if(cmap[s[i]-'a'] == 0){
            cmap[s[i]-'a'] = i+1;
        } else {
            // cmap[s[i]-'a'] = INT32_MAX;
            cmap[s[i]-'a'] = -1;
        }
    }

    int minmap = s.length()+1;
    // printArray(cmap, 26);

    for (int c : cmap) {
        // minmap = (c >= 0 && c < INT32_MAX && c < minmap) ? c : minmap;
        minmap = (c >= 1 && c < minmap) ? c : minmap;
    }

    return minmap == s.length()+1 ? -1 : minmap-1;
}

int main(){
    string a = makeRandomWord(10);
    cout << '"' << a << '"' << endl;
    int ans = firstUniqChar(a);
    cout << firstUniqChar(a) << endl;

    a = "leetcode";
    ans = firstUniqChar(a);
    cout << a << ", " << ans << endl;
    assert(ans == 0);

    a = "aabb";
    ans = firstUniqChar(a);
    cout << a << ", " << ans << endl;
    assert(ans == -1);

    a = "aa";
    ans = firstUniqChar(a);
    cout << a << ", " << ans << endl;
    assert(ans == -1);

    a = "a";
    ans = firstUniqChar(a);
    cout << a << ", " << ans << endl;
    assert(ans == 0);

    return 0;

}
