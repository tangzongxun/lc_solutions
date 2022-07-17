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
vector<TreeNode*> get_next_level(const vector<TreeNode*> &current_level, vector<vector<int>> &result) {
    vector<int> curr_result;
    vector<TreeNode*> next_level;
    for (auto node : current_level) {
        curr_result.push_back(node->val);
        if (node->left != nullptr) {
            next_level.push_back(node->left);
        }
        if (node->right != nullptr) {
            next_level.push_back(node->right);
        }
    }
    result.push_back(curr_result);
    return next_level;
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal_result;
        if (root == nullptr) {
            return traversal_result;
        }
        vector<TreeNode*> current_level;
        current_level.push_back(root);
        while (!current_level.empty()) {
            current_level = get_next_level(current_level, traversal_result);   
        }
        return traversal_result;
    } 
};
