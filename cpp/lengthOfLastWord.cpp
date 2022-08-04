#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;

// int lengthOfLastWord(string s) {
//     int curr = s.length()-1, start=-1;
//     while(curr >= 0){
//         if (start == -1 && s[curr] != ' ') {
//             start = curr;
//         } else if (start >= 0 && s[curr] == ' ') {
//             return start - curr;
//         } else if (start >= 0 &&  curr == 0) {
//             return start - curr + 1;
//         }
//         curr--;
//     }
//    return (start > -1)? 1 : -1;
// }


int lengthOfLastWord(string s) {
    int tail = s.length()-1, len = 0;
    while (tail >= 0 && s[tail] == ' ') {
        tail--;
    }

    while (tail >= 0 && s[tail] != ' ') {
        len++;
        tail--;
    }

    return len;
}

int main(){

    string str = "HEllo world";
    int ans = lengthOfLastWord(str);
    cout <<  "str: "  << str << ", " << "ans: "<< ans << endl;
    assert(ans == 5);

    str = "a    ";
    ans = lengthOfLastWord(str);
    cout <<  "str: "  << str << ", " << "ans: "<< ans << endl;
    assert(ans == 1);

    str = "a";
    ans = lengthOfLastWord(str);
    cout <<  "str: "  << str << ", " << "ans: "<< ans << endl;
    assert(ans == 1);

    str = "world";
    ans = lengthOfLastWord(str);
    cout <<  "str: "  << str << ", " << "ans: "<< ans << endl;
    assert(ans == 5);

    str = "world    ";
    ans = lengthOfLastWord(str);
    cout <<  "str: "  << str << ", " << "ans: "<< ans << endl;
    assert(ans == 5);

    str = "HEllo world    ";
    ans = lengthOfLastWord(str);
    cout <<  "str: "  << str << ", " << "ans: "<< ans << endl;
    assert(ans == 5);

    return 0;
}
