/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool isValid(TreeNode* root, long max, long min) {
    if (root == nullptr) {
        return true;
    }
    if (root->left != nullptr && root->left->val >= root->val) {
        return false;
    }
    if (root->right != nullptr && root->right->val <= root->val) {
        return false;
    }
    if (root->val >= max || root->val <= min) {
        return false;
    }
    return isValid(root->left, root->val, min)
        && isValid(root->right, max, root->val);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, numeric_limits<long>::max(), numeric_limits<long>::min());
    }
};
