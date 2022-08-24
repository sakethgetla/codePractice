#ifndef HELPERFUNCTIONS_H_
#define HELPERFUNCTIONS_H_
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>


using namespace std;

struct TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




void printBTree(TreeNode* root);


void printBSTree(TreeNode * node);


TreeNode * makeTreeNode(int val);

TreeNode * makeBTree(vector<int> &vals);


vector<vector<int>> levelOrderBTree(TreeNode* root) ;


// TreeNode * makeBTree(int * val, int length){
//     // min heep
//     //order: root, left, right.
//     // doesnt work great.
//     if (length > 0) {
//         TreeNode * root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
//         root->val = *val;
//         root->left = makeBTree(val+1, (length -1)/2 );
//         // root->left = makeBTree(val+1, length-1 );
//         if (length > 1) {
//             root->right = makeBTree(val+1 + ((length-1)/2), length-1-( (length-1)/2 ));
//             // root->right = nullptr;
//         } else {
//             root->right = nullptr;
//         }
//         return root;
//     }
//     return nullptr;
// }

void freeBTree(TreeNode * root);

TreeNode * insertToBSTree(TreeNode* root, int val);

TreeNode * makeBSTree(vector<int> vals);



int BTreeDepth(TreeNode * root);


void displayBTree(TreeNode * root);


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode *head);

// ListNode * makeList(int *ptr, int length) {
ListNode * makeList(vector<int> &vals) ;


void freeList(ListNode * head);



template <class T>
void printVector(vector<T> vec);


template <class T>
void print2dVec(vector<vector<T>> vec);

// template <class T>
// void printIterable(Array itr){
//     for (auto v : itr){
//         cout << v << "->" ;
//     }
//     cout << endl;
// }

template<typename Type>
void printArray(Type arr, int size);

// void generateRandomVec(vector<int> &vec, int low, int high){
//     for (int i = 0; i < vec.size(); i++) {
//         vec[i] = (rand()%( high - low )) + low;
//     }
// }

vector<int> generateRandomVec(int size, int low, int high);

vector<int> generateSortedVec(int size, int low, int high);


vector<int> generateSequenceVec(int low, int high);

// void generateSortedVec(vector<int> &vec, int low, int high){
//     generateRandomVec(vec, low, high);
//     sort(vec.begin(), vec.end());
// }




template<typename Type>
vector<vector<Type>> vecToMatrix(vector<Type> nums, int m, int n);


vector<vector<int>> makeRandomMatrix(int m, int n, int low, int high);


string makeRandomWord(int size);


string makeRandomSentence(int numWords);


#endif // HELPERFUNCTIONS_H_
