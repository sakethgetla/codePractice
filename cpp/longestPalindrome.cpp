
#include<iostream>
#include<string>


using namespace std;

string longestPalindrome(string s){
    string s1 = "";
    char *p;
    for(char c : s){
        // s1.append(c);
        s1 += '|';
        s1 += c;
        // s1.append();
    }

    // p = &s1[s1.length()-1] ;
    // cout << p << endl;

    // cout << s1.length() << endl;
    // s1 = &s1[1];
    s1 += '|';
    // cout << s1.length() << endl;

    // p = &s1[s1.length()-1] ;
    // cout << p << endl;
    // cout << s1 << endl;


    int centre = 0;
    int oldCentre = 0;
    int radius = 0;
    int oldRadius = 0;
    int maxRadius = 0;
    int maxRadiusCentre = 0;

    while(centre < s1.length()){
        radius = 0;
        while(centre - (1+radius) >= 0 && centre + (1+radius) < s1.length() && s1[centre - (1+radius)] == s1[centre + (1+radius)]){
            // cout << "here" << endl;
            radius++;
        }
        if (radius > maxRadius){
            maxRadius = radius;
            maxRadiusCentre = centre;
        }
        oldCentre = centre;
        oldRadius = radius;
        centre++;
    }
    // cout << maxRadiusCentre << endl;
    // cout << maxRadius << endl;
    s1[maxRadiusCentre+maxRadius+1] = '\0';
    s[(int)((1+ maxRadiusCentre+maxRadius )/2)] ='\0';
    // return &s1[( maxRadiusCentre-maxRadius )];
    return &s[(( maxRadiusCentre-maxRadius )/2)];
}

int main(){
    string a = "babad";
    cout << a << endl;
    string b = longestPalindrome(a);
    cout << b << endl;

    a = "a";
    cout << a << endl;
    b = longestPalindrome(a);
    cout << b << endl;

    a = "crabas";
    cout << a << endl;
    b = longestPalindrome(a);
    cout << b << endl;

}
