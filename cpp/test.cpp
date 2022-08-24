#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include "helperFunctions.cpp"
#include <bits/stdc++.h>
#include <cstring>



using namespace std;
    // const long &a = NULL;


// string makeRandomSentence(int numWords){
//     string s ;
//     for (int i = 0; i < numWords; i++) {
//         s += ' ';
//         s += makeRandomWord(1+( rand()%7 ));
//     }
//     return &s[1];
// }


void f(vector<int> &vals, int i) {
    if (!vals.empty()) {
        // ListNode *a = (struct ListNode*) malloc(sizeof(struct ListNode));
        cout << vals.back() << "-" << i << ", ";
        vals.pop_back();
        f(vals, i+1);
    } else {
        cout << endl;
    }
}





int main(){

    // string a = makeRandomSentence(10);
    // cout << '"' << a << '"' << endl;

    // testing random numbers.
    // int a = rand();
    // cout << a << ", " << a%26 << ", " << a%1000 << endl;
    //
    // cout << rand()%10 << endl;

    // int i = 0;
    // vector<int> a = {0,1,2,3,4,5};

    // cout << i << endl;
    // cout << a[++i] << endl;
    // cout << a[i++] << endl;
    // cout << i << endl;


    // vector<int> vals = generateSortedVec(pow(2, 4)-1, 0, pow(2, 4)-1);

    // vector<int> vals = generateSequenceVec(10, pow(2, 4));

    // vector<int> vec = generateRandomVec(30, 0, 10);
    vector<int> vec = generateRandomVec(50, 10, 100);

    // vector<int> vec = generateSortedVec(31, 10, 100);
    // vector<int> vec = {0};
    // vector<int> vec = {0,1};
    printVector(vec);
    TreeNode * root = makeBTree(vec);
    cout << bTreeDepth(root) << endl;

    displayBTree(root);

    // printBTree(root);
    // cout << endl;
    freeBTree(root);



    // vector<int> vals = {0,1,2,3,4,INT_MIN,5};
    // printVector(vals);

    // TreeNode * root = makeBTree(vals);
    // printBSTree(root);
    // cout << endl;
    // printBTree(root);
    // cout << endl;
    // freeBTree(root);

    // printBTree(root);



    // ListNode* head = makeList(a);
    // printListNode(head);
    // freeList(head);
    // f(a, 0);
    // cout << "hites" << endl;



    // typedef int pair[2];

    // pair p = {1,2};


    // int a = 60;
    // int c;

    // // binary make negative
    // c = ( a ^ -1) + 1;
    // cout << a << ": " << c << endl;


    // a = -1;
    // // binary make positive
    // c = ( a -1 ) ^ -1;
    // cout << a << ": " << c << endl;

    // a = 21;
    // cout << a << ": " << ( a << 2 ) << endl;
    // a = -37;
    // cout << a << ": " << ( a << 2 ) << endl;

    // cout << INT32_MIN << ", " << abs(INT32_MIN) << ", " << abs(INT32_MIN) -1 << endl;

    // vector<int> b = {};
    // cout << b.size() << endl;


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



    return 0;
}
