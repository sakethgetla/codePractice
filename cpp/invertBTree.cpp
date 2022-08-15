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

// =================================================================
// ==31==ERROR: AddressSanitizer: alloc-dealloc-mismatch (malloc vs operator delete) on 0x603000000130
//     #5 0x7f9dee62e0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
// 0x603000000130 is located 0 bytes inside of 24-byte region [0x603000000130,0x603000000148)
// allocated by thread T0 here:
//     #5 0x7f9dee62e0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
// ==31==HINT: if you don't care about these errors you may set ASAN_OPTIONS=alloc_dealloc_mismatch=0
// ==31==ABORTING

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
