#include <cstdlib>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
    if (root) {
        vector<int> curr = {root->val};
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        curr.insert(curr.end(), left.begin(), left.end());
        curr.insert(curr.end(), right.begin(), right.end());
        // left.insert(left.end(), right.begin(), right.end());
        return curr;
    } else {
        return {};
    }

}


void inorderTraversal(TreeNode* root, vector<int> &nodes) {
    if (root) {
        // nodes = inorderTraversal(root->left, nodes);
        inorderTraversal(root->left, nodes);

        nodes.push_back(root->val);

        inorderTraversal(root->right, nodes);
    }
}


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nodes;
    inorderTraversal(root, nodes);
    return nodes;

}


void postorderTraversal(TreeNode* root, vector<int> &nodes) {
    if (root) {
        postorderTraversal(root->right, nodes);
        postorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
    }
}


vector<int> postorderTraversal(TreeNode* root) {
   vector<int> nodes;
   postorderTraversal(root, nodes);
   return nodes;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    vector<vector<int>> vals;
    q.push({ root, 0 });
    pair<TreeNode*, int> curr;
    vector<int> row;
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        cout << curr.first << ", " << curr.first->val << ", " << curr.second << endl;
    }
    return vals;
}

int maxDepth(TreeNode* root) {
    return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
}

bool isSymmetric(TreeNode* t1, TreeNode* t2) {
    // if ( (t1 == nullptr && t2 == nullptr) || (t1 && t2 && t1->left->val == t2->right->val && t2->left->val == t1->right->val && isSymmetric(t1->left, t2->right) && isSymmetric(t2->left, t1->right)) ) {
    if ( (t1 == nullptr && t2 == nullptr) || (t1 && t2 && t1->val == t2->val && isSymmetric(t1->left, t2->right) && isSymmetric(t2->left, t1->right)) ) {
        return true ;
    } else {
        return false ;
    }
}

bool isSymmetric(TreeNode* root) {
    return isSymmetric(root->left, root->right);
}

int main(){


    return 0;
}
