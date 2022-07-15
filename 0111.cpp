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
    int minDepth(TreeNode* root) {
        int depth = 0;
        if (nullptr == root) return 0;
        std::queue<TreeNode*> level;
        std::queue<TreeNode*> next_level;
        level.push(root);
        while (true) {
            depth++;
            while (!level.empty()) {
                TreeNode *node = level.front();
                level.pop();
                if (!node->left && !node->right) {
                    // is leaf node
                    return depth;
                }
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
            }
            level = std::move(next_level);
            next_level = decltype(next_level){};
        }
    }
};
