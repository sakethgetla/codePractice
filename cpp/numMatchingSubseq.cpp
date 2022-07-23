#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << "->" ;
    }
    cout << endl;
    // cout << "eof" << endl;
}


template <class T>
void print2DVector(vector<vector<T>> vec){
    cout << '[' << endl;
    for (vector<T> v : vec){
        printVector(v);
    }
    cout <<']' << endl;
    // cout << endl;
}

// int numMatchingSubseq(string s, vector<string> &words){
//     int num = 0;

//     int i = 0;
//     for(string word: words){
//         i = 0;
//         for(char c: s){
//             if(c == word[i])
//                 i++;
//             if(i >= word.length()){
//                 num++;
//                 break;
//             }
//         }
//     }

//     return num;
// }


// int nextOccur(vector<int> vec, int i){
//     for(int v: vec){
//         if (i < v){
//             return v;
//         }
//     }
//     return -1;
// }

// int numMatchingSubseq(string s, vector<string> &words){
//     // unordered_map<char, vector<int>> m;
//     vector<int> occur[26];
//     // int i = 0;
//     int num = 0;
//     // for (char c: s){
//     for(int i = 0 ; i < s.length() ; i++){
//         occur[s[i]-'a'].push_back(i);
//     }

//     for(string word : words){
//         int curr = -1;
//         int match = 0;
//         // find word
//         bool found = true;
//         for(char c: word){

//             found = false;
//             for(int v : occur[c-'a']){
//                 if (curr < v){
//                     curr = v;
//                     found = true;
//                     break;
//                 }
//             }

//             if (!found){
//                 break;
//             }
//         }
//         if (found){
//             num++;
//         }
//     }

//     return num;

// }

int numMatchingSubseq(string s, vector<string> &words){
    vector<char*>  pending[26];
    int num = 0;

    // for (int i = 0; i < s.length() ; i++){
    for (int i = 0; i < words.size() ; i++){
        pending[words[i][0]-'a'].push_back(&words[i][0]);
    }


    // for (vector<char*> c: pending){
    // for (int i = 0; i < 26 ; i++){
    //     cout << (char) (i+'a') << ", " ;
    //     printVector(pending[i]);
    // }

    for(char c : s){
        vector<char*> curr = pending[c-'a'];
        pending[c-'a'] = {};

        for (char * t: curr){
            t++;
            if (*t == 0){
                num++;
            } else {
                pending[*t-'a'].push_back(t);
            }
        }
    }




    return num;
}

int main(){
    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace", "abcde"};
    // s = "a";
    cout << s << endl;
    cout << numMatchingSubseq(s, words) << endl;

    s = "dsahjpjauf";
    words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    cout << numMatchingSubseq(s, words) << endl;

    return 0;
}
