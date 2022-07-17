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
class Solution {
public:
    bool isLeaf(TreeNode *node) {
        return !node->left && !node->right;
    }
    bool hasPathSumImpl(int sum, TreeNode *node, int target) {
        if (!node) return false;
        sum += node->val;
        if (isLeaf(node) && sum == target) return true;
        return hasPathSumImpl(sum, node->left, target)
            || hasPathSumImpl(sum, node->right, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return hasPathSumImpl(sum, root, targetSum);
    }
};
