
#include <cstdlib>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int atoi(string s) {
    int start = 0;
    int neg = 0;
    // string numStr = "";
    while (s[0] == ' ') {
        s = &s[1];
    }
    // cout << s << endl;
    if(s[0] == '-'){
        neg=1;
        s = &s[1];
    } else if(s[0] == '+')
        s = &s[1];


    while (s[0] == '0') {
        s = &s[1];
    }


    long out = 0;
    long high = pow(2, 31) -1;
    long low = -pow(2, 31);

    for (char c : s){
        // cout << numStr << endl;
        if(c>='0' && c<='9'){
            // numStr += c;

            out *= 10;
            out += c -'0';
            // if (out > high || (out> high +1 && neg) )
            //     return high;

            if (out > high +1 && neg)
                return low;
            else if (out > high && !neg)
                return high;

        } else {
            break;
        }
    }

    // // cout << numStr << endl;
    // long out = 0;
    // // long out = numStr[0] -'0';
    // long high = pow(2, 31) -1;
    // long low = -pow(2, 31);
    // // cout << low << endl;
    // // cout << high << endl;

    // // numStr = &numStr[1];
    // for (char c : numStr){
    //     out *= 10;
    //     out += c -'0';
    //     // if (out > high || (out> high +1 && neg) )
    //     //     return high;

    //     if (out > high +1 && neg)
    //         return low;
    //     else if (out > high && !neg)
    //         return high;
    // }

    if(neg)
        out *= -1;

    return out;
}

int main(int argc, char *argv[]) {
    string s = "   000020130 aristeni";
    cout << s << endl;
    cout << atoi(s) << endl;

    s = " -42";
    cout << s << endl;
    cout << atoi(s) << endl;

    s = " -09210290342";
    cout << s << endl;
    cout << atoi(s) << endl;

    s = " 9210290342";
    cout << s << endl;
    cout << atoi(s) << endl;
    return 0;
}
