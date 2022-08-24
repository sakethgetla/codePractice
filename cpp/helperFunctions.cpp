#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <cstring>
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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



void printBTree(TreeNode* root){
    // min heep
    //order: root, left, right.
    if (root != nullptr) {
        cout << root->val << ", ";
        printBTree(root->left);
        printBTree(root->right);
    } else {
        cout << "N, " ;
    }
}


void printBSTree(TreeNode * node){
    // order: left, root, right
    if (node == nullptr) {
        cout << ", N";
    } else {
        printBSTree(node->left);
        cout << ", " << node->val;
        printBSTree(node->right);
    }
}


TreeNode * makeTreeNode(int val){
    // null = INT MIN
    if (val == INT_MIN) {
        return nullptr;
    } else {
        TreeNode * node = (TreeNode*) malloc(sizeof(TreeNode));
        node->val = val;
        node->right = nullptr;
        node->left = nullptr;
        return node;
    }
}

TreeNode * makeBTree(vector<int> &vals){
    queue<TreeNode *> q;
    TreeNode* root = makeTreeNode(vals[0]);
    TreeNode* curr = root;

    for (int i = 1; i < vals.size(); i++) {
        if (curr->left) {
            curr->right = makeTreeNode(vals[i]);
            q.push(curr->right);
            curr = q.front();
            q.pop();
        } else {
            curr->left = makeTreeNode(vals[i]);
            q.push(curr->left);
        }

    }
    return root;
}


vector<vector<int>> levelOrderBTree(TreeNode* root) {
    if (root == nullptr )
        return {};
    queue<pair<TreeNode*, int>> q;
    vector<vector<int>> vals;
    q.push({ root, 0 });
    pair<TreeNode*, int> curr;
    // vector<int> row;
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        if (curr.first){
            if ( curr.second == vals.size()){
                vals.push_back(vector<int>{});

            }
            vals[curr.second].push_back(curr.first->val);
            // cout << curr.first << ", " << curr.first->val << ", " << curr.second << endl;
            q.push({curr.first->left, curr.second +1});
            q.push({curr.first->right, curr.second +1});
        }

    }
    return vals;

}


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

void freeBTree(TreeNode * root){
    if (root != nullptr) {
        freeBTree(root->left);
        freeBTree(root->right);
        free(root);
    }
}

TreeNode * insertToBSTree(TreeNode* root, int val){
    if (root == nullptr){
        return makeTreeNode(val);
    } else if (root->val >= val) {
        root->left = insertToBSTree(root->left, val);
        return root;
    } else if (root->val < val) {
        root->right = insertToBSTree(root->right, val);
        return root;
    } else {
        assert(false);
        return root;
    }
}

TreeNode * makeBSTree(vector<int> vals){
    // order left -> root -> right.
    TreeNode *node = nullptr;
    // vals.pop_back();

    // printVector(vals);
    // cout << vals.back() << endl;

    for (int i = 0 ; i < vals.size() ; i ++){
        node = insertToBSTree(node, vals[i]);
    }
    // for (int val : vals) {
    // }
    return node;
}



int bTreeDepth(TreeNode * root){
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + max(bTreeDepth(root->left), bTreeDepth(root->right));
    }
}


void displayBTree(TreeNode * root){
    queue<TreeNode * > qu;
    qu.push(root);
    TreeNode * curr;
    int lvl = 0, depth = bTreeDepth(root), valSize = 2, spSize = 2, width = pow(2, depth-1)*(valSize+spSize) ;

    // width -= spSize;
    // width -= spSize;

    cout << "Depth: " << depth << ", width: " << width << endl;

    while (!qu.empty() && lvl < depth) {
        string row(width, '-');
        // for (int i = ((width/pow(2, lvl))/2) ; i < width; i += 1+(width/pow(2, lvl)) ) {
        for (int i = ((width/pow(2, lvl))/2) ; i < width; i += (width/pow(2, lvl)) ) {
            curr = qu.front();
            qu.pop();
            if (curr) {
                // cout << curr->val << " ";
                row[i] = '0' + (curr->val/10);
                row[i+1] = '0' + (curr->val%10);
                qu.push(curr->left);
                qu.push(curr->right);
            } else {
                // cout << "NN ";
                row[i] = 'N';
                row[i+1] = 'N';
                qu.push(nullptr);
                qu.push(nullptr);
            }
        }
        cout << row << endl;
        lvl ++;
    }

}


// void displayBTree(TreeNode * root){
//     int depth = BTreeDepth(root), lvl = 0, valSize = 2, spaceSize = 4, numSpaces;
//     queue<TreeNode*> q;
//     TreeNode * curr ;
//     q.push(root);

//     cout << "Depth: " << depth << endl;
//     while (!q.empty() && lvl < depth) {

//         // numSpaces = (((spaceSize+valSize)*pow(2, depth))/( lvl+2 ))-valSize;
//         // numSpaces = ((spaceSize + valSize)*pow(2, depth)/(pow(2, lvl+2)*2)) ;
//         int a = spaceSize + valSize, b = pow(2, depth-1), c = (pow(2, lvl) + 1);
//         numSpaces = (a*b/c);
//         // numSpaces = (depth-1-lvl)*(spaceSize+valSize);
//         // cout << a << " * " << b << " / "<< c << " = " << numSpaces << endl;
//         // for (int j = 0; j < numSpaces ; j++) {
//         //     cout <<  ' ';
//         // }

//         cout << numSpaces;
//         string row(a*b, '_');
//         // for (int i = 0; i < pow(2, lvl) && !q.empty() ; i++) {
//         for (int i = 1; i <= pow(2, lvl) ; i++) {

//             // for (int j = 0; j < numSpaces-1 ; j++) {
//             //     cout <<  ' ';
//             // }

//             curr = q.front();
//             q.pop();
//             if (curr) {
//                 // cout << curr->val << ", ";
//                 // cout << curr->val;
//                 row[( i*numSpaces )-1] = '0' + curr->val/10;
//                 row[( i*numSpaces )] = '0' + curr->val%10;
//                 q.push(curr->left);
//                 q.push(curr->right);
//             } else {
//                 // cout << "NN";
//                 // cout << "NN, ";
//                 row[( i*numSpaces )-1] = 'N';
//                 row[( i*numSpaces )] = 'N';
//                 // row[( i*numSpaces )] = curr->val/10;
//                 q.push(nullptr);
//                 q.push(nullptr);
//             }

//             // numSpaces = (spaceSize*pow(2, depth-1))/pow(2, lvl+1 );
//             // for (int j = 0; j < numSpaces -1 ; j++) {
//             //     cout << ' ';
//             // }

//         }

//         cout << row << endl;
//         lvl++;
//     }


// }



void printListNode(ListNode *head){
    if (head != nullptr){
        cout << head->val << "->" ;
        printListNode(head->next);
    } else {
        cout << "null" << endl;
    }
}

// ListNode * makeList(int *ptr, int length) {
ListNode * makeList(vector<int> &vals) {
    if (!vals.empty()) {
        // ListNode n = ListNode(*ptr, makeList(&ptr[1], length--));
        ListNode *a = (struct ListNode*) malloc(sizeof(struct ListNode));
        a->val = vals.back();
        vals.pop_back();
        a->next = makeList(vals);
        // a = ListNode(*ptr, makeList(&ptr[1], length--));
        return a;
    }
    return nullptr;
}


void freeList(ListNode * head){
    if (head != nullptr) {
        ListNode * n = head->next;
        free(head);
        freeList(n);
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

// void generateRandomVec(vector<int> &vec, int low, int high){
//     for (int i = 0; i < vec.size(); i++) {
//         vec[i] = (rand()%( high - low )) + low;
//     }
// }

vector<int> generateRandomVec(int size, int low, int high){
    vector<int> vec;
    for (int i = 0; i < size; i++) {
        vec.push_back((rand()%( high - low )) + low);

    }
    return vec;
}

vector<int> generateSortedVec(int size, int low, int high){
    vector<int> vec = generateRandomVec(size, low, high);
    sort(vec.begin(), vec.end());
    return vec;
}


vector<int> generateSequenceVec(int low, int high){
    vector<int> vec(high-low);
    for (int i = low; i < high; i++ ){
        vec[i-low] = i;
    }
    return vec;
}

// void generateSortedVec(vector<int> &vec, int low, int high){
//     generateRandomVec(vec, low, high);
//     sort(vec.begin(), vec.end());
// }




template<typename Type>
vector<vector<Type>> vecToMatrix(vector<Type> nums, int m, int n){
    vector<vector<Type>> matrix;
    for (int j = 0; j < m; j++) {
        vector<Type> row;
        for (int i = 0; i < n; i++) {
            // cout <<(j*n) << ", " << i << endl;
            row.push_back(nums[(j*n)+i]);
        }
        matrix.push_back(row);
    }
    return matrix;
}


vector<vector<int>> makeRandomMatrix(int m, int n, int low, int high){
    vector<vector<int>> matrix;
    for (int j = 0; j < m; j++) {
        matrix.push_back(generateRandomVec(n, low, high));
    }
    return matrix;
}


string makeRandomWord(int size){
    char s[size];
    for (int i = 0; i < size-1; i++) {
        s[i] = 'a'+(rand()%26) ;
    }
    s[size-1] = '\0';
    return s;
}


string makeRandomSentence(int numWords){
    string s ;
    for (int i = 0; i < numWords; i++) {
        s += ' ';
        s += makeRandomWord(1+( rand()%7 ));
    }
    return &s[1];
}
