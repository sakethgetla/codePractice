#include <cstdlib>
#include <future>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

void reverseString(vector<char>& s) {
    int l = 0, r = s.size()-1, temp;

    while (r > l) {
        temp = s[r];
        s[r] = s[l];
        s[l] = temp;
        r--;
        l++;
    }

}

int lengthOfLongestSubstring(string s) {
    int start=0, maxlen=0;
    unordered_map<char, int> umap;
    for (int i = 0; i < s.length(); i++) {
        if (umap.find(s[i]) != umap.end() && umap[s[i]] >= start) {
            start = umap[s[i]] +1;
        } else {
            maxlen = max(i - start, maxlen);
        }
        umap[s[i]] = i;
    }
    return s.length() == 0 ? 0: maxlen+1;

}

bool checkInclusion(string s1, string s2) {
    vector<int> counts('z'+1, 0);

    for (char c  : s1) {
        counts[c] ++;
    }


    for (int i = 0, j = 0; i < s2.length(); ) {
        if (counts[s2[i] ] == 0) {
            if (j < i) {
                counts[s2[j]] ++;
                j++;
            } else {
                i++;
                j++;
            }
        } else {
            counts[s2[i]] --;
            i++;
        }
        if (i-j == s1.length()) {
            return true;
        }
    }
    return false;

}

int main(){

    // string s1 = getSubset(s2, 10);
    string s1 = makeRandomWord(10);
    string s2 = makeRandomWord(10) + getSubset(s1, 10);


    bool ans ;
    cout << s2 << ": " << s1 << endl;

    ans = checkInclusion(s1, s2);
    cout << s2 << ": " << s1 << ": " << ans  << endl;

    s1 += 'a';
    ans = checkInclusion(s1, s2);
    cout << s2 << ": " << s1 << ": " << ans  << endl;

    s1 = "ab";
    s2 = "eidboaoo";
    ans = checkInclusion(s1, s2);
    cout << s2 << ": " << s1 << ": " << ans  << endl;

    s1 = "a";
    s2 = "b";
    ans = checkInclusion(s1, s2);
    cout << s2 << ": " << s1 << ": " << ans  << endl;

    s1 = "b";
    s2 = "b";
    ans = checkInclusion(s1, s2);
    cout << s2 << ": " << s1 << ": " << ans  << endl;

    s1 = "ab";
    s2 = "eidbaooo";
    ans = checkInclusion(s1, s2);
    cout << s2 << ": " << s1 << ": " << ans  << endl;



    // vector<char> s = {'n'};
    // string s = "abcabcbb";
    // int ans;
    // ans = lengthOfLongestSubstring(s);
    // cout << s << ": " << ans << endl;

    // s = "bbbbb";
    // ans = lengthOfLongestSubstring(s);
    // cout << s << ": " << ans << endl;


    // s = "";
    // ans = lengthOfLongestSubstring(s);
    // cout << s << ": " << ans << endl;

    // s = "pwwkew";
    // ans = lengthOfLongestSubstring(s);
    // cout << s << ": " << ans << endl;


    return 0;
}
