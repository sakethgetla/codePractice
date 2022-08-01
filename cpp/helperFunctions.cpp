#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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



template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << "->" ;
    }
    cout << endl;
}


void print2dVec(vector<vector<int>> vec){
    for (vector<int> v : vec){
        printVector(v);
    }
}

int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    print2dVec(matrix);

    return 0;
}
