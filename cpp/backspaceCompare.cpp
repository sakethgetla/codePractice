#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.cpp"

using namespace std;

bool backspaceCompare(string s, string t) {
    // int i = s.size()-1, j = t.size()-1, scnt = 0, tcnt = 0, cnt=0;
    int cnt=0;

    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '#') {
                cnt++;
        } else if (cnt > 0) {
            s[i] = '#';
            cnt--;
        }
    }


    for (int i = t.size()-1; i >= 0; i--) {
        if (t[i] == '#') {
                cnt++;
        } else if (cnt > 0) {
            t[i] = '#';
            cnt--;
        }
    }



    return true;

}

int main(){
    string s = "ab#c", t = "ad#c";
    bool ans = backspaceCompare(s, t);
    cout << s << ", " << t << ", " << ans << endl;
    assert(ans);

    s = "ab##", t = "c#c#";
    ans = backspaceCompare(s, t);
    cout << s << ", " << t << ", " << ans << endl;
    assert(ans);

    s = "ab##", t = "c#c";
    ans = backspaceCompare(s, t);
    cout << s << ", " << t << ", " << ans << endl;
    assert(!ans);

    return 0;
}
