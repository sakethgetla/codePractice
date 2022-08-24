#include <climits>
#include <cstdlib>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cassert>
#include <vector>
#include "helperFunctions.cpp"

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


TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) {
        return nullptr;
    } else if (root->val == val) {
        return root;
    }else {
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
}

// bool findTargetBST(TreeNode* root, int k) {
//     // 2 Sum in BST

//     stack<TreeNode*> stk;
//     stk.push(root);
//     TreeNode* curr ;
//     unordered_map<int, bool> mp;

//     while (!stk.empty()) {
//         curr = stk.top();
//         stk.pop();

//         if (mp.find(k - curr->val) != mp.end())
//             return true;

//         if (curr->right)
//             stk.push(curr->right);

//         if (curr->left)
//             stk.push(curr->left);

//         mp[curr->val] = true;

//     }

//     return false;
// }


bool findTargetBST(TreeNode* root, int k, unordered_map<int, bool> &mp) {
    if (root ){
        if (mp.find(k - root->val) != mp.end()) {
            return true;
        } else {
            mp[root->val] = true;
            return findTargetBST(root->left, k, mp) || findTargetBST(root->right, k, mp);
        }
    } else {
        return false;
    }
}

bool findTargetBST(TreeNode* root, int k) {
    // 2 Sum in BST
    unordered_map<int, bool> mp;
    return findTargetBST(root, k, mp);
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return nullptr;
    } else if (root == p || root == q){
        return root;
    } else {
        TreeNode * l = lowestCommonAncestor(root->left, p, q), * r = lowestCommonAncestor(root->left, p, q);
        if (!l) {
            return r;
        } else if (!r) {
            return l;
        }else {
            return root;
        }
    }
    // return nullptr;
}

int main(){
    // vector<int> vec = {4,2,7,1,INT_MIN,7,9,10};
    // vector<int> vec = generateSortedVec(5, 10, 100);
    vector<int> vec = generateRandomVec(6, 10, 100);

    // TreeNode * tree = makeBTree(vec);
    TreeNode * tree = makeBSTree(vec);
    // int target = 4;

    // TreeNode * p = searchBST(tree, 77);
    // TreeNode * q = searchBST(tree, 83);

    cout << BTreeDepth(tree) << endl;

    printVector(vec);
    print2dVec(levelOrderBTree(tree));
    displayBTree(tree);

    // TreeNode* ans = lowestCommonAncestor(tree, p, q);

    // cout << "p: " << p->val << ", q: " << q->val << ", ans: " << ans->val << endl;




    // print2dVec(levelOrderBTree(tree));
    // cout << "target: " << target << ", " << findTargetBST(tree, target) << endl;
    // cout << "target: " << target << ", " << findTargetBST(tree, target) << endl;

    // print2dVec(levelOrderBTree(tree));
    // print2dVec(levelOrderBTree(searchBST( tree, 2 )));
    // print2dVec(levelOrderBTree(searchBST( tree, 12 )));

    freeBTree(tree);


    return 0;
}
