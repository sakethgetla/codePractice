#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;

void KMP(string str, int* lps){
    int i = 1, len = 0;
    lps[0] = 0;

    while (i < str.length()) {
        if(str[i] == str[len]){
            len ++;
            lps[i] = len;
            i++;
        } else if (len != 0) {
            len = lps[len-1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
}

int strStr(string haystack, string needle) {

    if (needle.empty()) {
        return 0;
    }

    int ihaystack = 0, ineedle = 0;
    int lps[needle.length()];
    KMP(needle, lps);
    printArray(lps, needle.length());

    while (ihaystack < haystack.length()) {
        if (haystack[ihaystack] == needle[ineedle]) {
            ineedle++;
            ihaystack++;
            if (ineedle == needle.length()) {
                return ihaystack-ineedle;
            }
        }else {
            if (ineedle == 0) {
                ihaystack++;
            }else {
                ineedle = lps[ineedle-1];
            }
        }

    }
    return -1;
}


int main(){
    // string  needle = "abczzabczzbc";
    // string  needle = "abacababba";
    // // int const lps[2] = {2};
    // int lps[needle.length()] ;
    // int ind[needle.length()] ;

    // for (int i = 0; i < needle.length(); i++) {
    //     lps[i] = 0;
    //     ind[i] = i;
    // }

    // // cout << needle << endl;
    // KMP(needle, lps);
    // printArray(ind, needle.length());
    // printArray(needle, needle.length());
    // printArray(lps, needle.length());

    string haystack = "hello", needle = "ll";
    int ans = strStr(haystack, needle);
    cout << haystack << ", " << needle << ", " << ans << endl;
    assert(ans == 2);


    haystack = "aaaaa", needle = "";
    ans = strStr(haystack, needle);
    cout << haystack << ", " << needle << ", " << ans << endl;
    assert(ans == 0);

    haystack = "aaaaa", needle = "bba";
    ans = strStr(haystack, needle);
    cout << haystack << ", " << needle << ", " << ans << endl;
    assert(ans == -1);



    haystack = "mississippi", needle = "issip";
    cout << haystack << ", " << needle << ", " ;
    ans = strStr(haystack, needle);
    cout << ans << endl;
    assert(ans == 4);

    return 0;
}
