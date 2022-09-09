#include <cctype>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

using namespace std;

bool isPalindrome(string s) {
    int low = 0, high = s.length()-1;
    while (low < high) {
        if (!isalnum(s[low])) {
            low++;
        } else if (!isalnum(s[high])) {
            high--;
        } else if (tolower(s[low]) != tolower(s[high])) {
            return false;
        }else {
            low++;
            high--;
        }
    }
    return true;
}

int main(){
    string s;
    bool ans;
    s = "A man, a plan, a canal: Panama";
    ans = isPalindrome(s);
    cout << s << ", " << ans << endl;
    // printf("%s, %d\n", s, ans);


    s = "race a car";
    ans = isPalindrome(s);
    cout << s << ", " << ans << endl;

    s = "  ";
    ans = isPalindrome(s);
    cout << s << ", " << ans << endl;

    s = "0P";
    ans = isPalindrome(s);
    cout << s << ", " << ans << endl;

    // cout << isal('0')<< endl;

    return 0;
}
