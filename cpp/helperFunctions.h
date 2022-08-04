#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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


void printBTree(TreeNode* root){
    //order: root, left, right.
    if (root != nullptr) {
        cout << root->val << ", ";
        printBTree(root->left);
        printBTree(root->right);
    } else {
        cout << "null, " ;
    }
}

TreeNode * makeBTree(int * val, int length){
    //order: root, left, right.
    // doesnt work great.
    if (length > 0) {
        TreeNode * root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        root->val = *val;
        root->left = makeBTree(val+1, (length -1)/2 );
        // root->left = makeBTree(val+1, length-1 );
        if (length > 1) {
            root->right = makeBTree(val+1 + ((length-1)/2), length-1-( (length-1)/2 ));
            // root->right = nullptr;
        } else {
            root->right = nullptr;
        }
        return root;
    }
    return nullptr;
}

void freeBTree(TreeNode * root){
    if (root != nullptr) {
        freeBTree(root->left);
        freeBTree(root->right);
        free(root);
    }
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



template <class T>
void printVector(vector<T> vec){
    for (T v : vec){
        cout << v << ", " ;
    }
    cout << endl;
}


template <class T>
void print2dVec(vector<vector<T>> vec){
    for (vector<T> v : vec){
        printVector(v);
    }
}

// template <class T>
// void printIterable(Array itr){
//     for (auto v : itr){
//         cout << v << "->" ;
//     }
//     cout << endl;
// }

template<typename Type>
void printArray(Type arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void generateRandomVec(vector<int> &vec, int low, int high){
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = (rand()%( high - low )) + low;
    }
}

void generateSortedVec(vector<int> &vec, int low, int high){
    generateRandomVec(vec, low, high);
    sort(vec.begin(), vec.end());
}



// template<typename Type, int Size>
// template<typename Type>
// void printIterable(Type const(& itr)) {
//     for (auto v : itr){
//         cout << v << "->" ;
//     }
//     cout << endl;
// }

// int main(){
//     vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
//     print2dVec(matrix);

//     return 0;
// }
