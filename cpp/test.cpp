#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
    // const long &a = NULL;


void p(int i){
 cout << i << endl;
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode *head){
    if (head != nullptr){
        cout << head->val << "->" ;
        printListNode(head->next);
    } else {
        cout << "null" << endl;
    }
}

ListNode * makeList(int *ptr, int length) {
    if (length > 0){
        // ListNode n = ListNode(*ptr, makeList(&ptr[1], length--));
        ListNode *a = (struct ListNode*) malloc(sizeof(struct ListNode));
        a->val = *ptr;
        a->next = makeList(&ptr[1], --length);
        // a = ListNode(*ptr, makeList(&ptr[1], length--));
        return a;
    }
    return nullptr;
}

void freeList(ListNode * head){
    if (head != nullptr) {
        freeList(head->next);
        free(head);
    }
}

int main(){
    // int i = 0;
    // cout << i << endl;
    // p(i++);
    // p(i);
    // // p(++i);
    // // i++;
    // cout << i << endl;


    int a[5] = {1,2,3,46,68};
    ListNode* head = makeList(a, 5);
    printListNode(head);
    freeList(head);



    typedef int pair[2];

    pair p = {1,2};


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



    // cout << c << endl;
    // c++;
    // cout << c << endl;


    return 0;
}
