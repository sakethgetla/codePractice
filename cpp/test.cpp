#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
    // const long &a = NULL;


void p(int i){
 cout << i << endl;
}

int main(){
    // int i = 0;
    // cout << i << endl;
    // p(i++);
    // p(i);
    // // p(++i);
    // // i++;
    // cout << i << endl;


    int a = 60;
    int c;

    // binary make negative
    c = ( a ^ -1) + 1;
    cout << a << ": " << c << endl;


    a = -1;
    // binary make positive
    c = ( a -1 ) ^ -1;
    cout << a << ": " << c << endl;


    // string pointers
    // string s = "abcd";
    // cout << s << endl;
    // char *c = &s[0];

    // vector<char*> a = {&s[0], &s[2]};


    // for(char* b: a){
    //     // cout << (char) *b << endl;
    //     cout << *b << endl;
    //     b++;
    //     cout << *b << endl;
    // }


    // cout << INT32_MIN << endl;
    // cout << (false == false) << endl;



    // cout << c << endl;
    // c++;
    // cout << c << endl;


    return 0;
}
