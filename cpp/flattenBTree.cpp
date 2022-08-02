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
    } else {
        cout << "null, " ;
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
    TreeNode * curr = root;
    // TreeNode * temp = nullptr;
    vector<TreeNode*> stack ;
    if (root != nullptr) {
        while(curr->right != nullptr || curr->left != nullptr || !stack.empty()){
            if (curr->left != nullptr) {
                if (curr->right != nullptr){
                    stack.push_back(curr->right);
                }
                curr->right = curr->left;
                curr->left = nullptr;
            }

            if (curr->right == nullptr){
                curr->right = stack.back();
                stack.pop_back();
            }

            curr = curr->right;
        }

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

    // int a[5] = {1,2,3,4,5};
    int len = 5;
    int a[5] = {1,2,3,4,5};
    // int a[2] = {1,2};
    // a = {1,2};

    vector<TreeNode*> stack = {};
    assert(stack.empty());

    TreeNode * root = makeBTree(a, len);
    printBTree(root);
    cout << endl;

    flatten(root);
    printBTree(root);
    cout << endl;

    freeBTree(root);

    return 0;
}
