#include <cstdlib>
#include <unordered_map>
#include <cassert>
#include "helperFunctions.h"

using namespace std;


// TreeNode* invertTree(TreeNode* left, TreeNode* right) {

// }

TreeNode* invertTree(TreeNode* root) {
    if (root) {
        TreeNode * temp = root->left;
        // root->left = root->right;
        // root->right = temp;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    } else {
        return nullptr;
    }
}

bool hasPathSum(TreeNode* root, int targetSum) {

    if (root) {
        int val = targetSum - root->val;
        if (root->left && root->right && targetSum == 0) {
            return true;
        } else {
            return hasPathSum(root->left, val) || hasPathSum(root->right, val) ;
        }
        // return (val > 0 ) ? hasPathSum(root->left, val) || hasPathSum(root->right, val) : false;
    } else {
        return false;
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root) {
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
            return root;
        } else {
            root->right = insertIntoBST(root->right, val);
            return root;
        }
    } else {
        // TreeNode n = TreeNode(val);
        // return &n;
        TreeNode * node = (TreeNode*) malloc(sizeof(TreeNode));
        node->val = val;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
}

int main(){
    // vector<int> vals = generateSequenceVec(0, pow(2, 4));
    vector<int> vals ;
    vals = {4,2,7,1,3};
    printVector(vals);

    TreeNode * root = makeBTree(vals);
    print2dVec(levelOrderBTree(root));
    root = insertIntoBST(root, 5);
    print2dVec(levelOrderBTree(root));
    freeBTree(root);

    return 0;
}
