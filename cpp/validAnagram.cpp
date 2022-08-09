#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;

// bool isAnagram(string s, string t) {
//     if (s.length() != t.length()) {
//         return false;
//     }
//     unordered_map<char, int> l;

//     for (char c : s) {
//         if(l.find(c) == l.end())
//             l[c] = 1;
//         else
//             l[c]++;
//     }

//     for (char c : t) {
//         if(l.find(c) == l.end())
//             return false;
//         else
//             l[c]--;

//         if (l[c] == 0)
//             l.erase(c);

//     }
//     return l.empty() ? true : false;
// }

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }

    for (int i : arr) {
        if (i != 0) {
            return false;
        }
    }
    return true;


}

int main(){
    string s = "anagram", t = "nagaram";
    bool ans = isAnagram(s, t);
    assert(ans);
    cout << s << ", " << t << ", " << ans << endl;

    s = "rat";
    t = "ratt";
    ans = isAnagram(s, t);
    assert(!ans);
    cout << s << ", " << t << ", " << ans << endl;

    return 0;
}
