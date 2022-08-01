#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printBTree(TreeNode* root){
    // root, left, right.
    if (root != nullptr) {
        cout << root->val << ", ";
        printBTree(root->left);
        printBTree(root->right);
    }
}

TreeNode * makeBTree(int * val, int length){
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

void flatten(TreeNode* root) {
    if (root != nullptr) {

    }

}

void freeBTree(TreeNode * root){
    if (root != nullptr) {
        freeBTree(root->left);
        freeBTree(root->right);
        free(root);
    }
}



int main(){

    int a[5] = {1,2,3,4,5};

    TreeNode * root = makeBTree(a, 5);
    printBTree(root);
    cout << endl;
    freeBTree(root);

    return 0;
}
