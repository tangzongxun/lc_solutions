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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (nullptr == root) {
            return result;
        }
        std::stack<TreeNode*> this_level;
        this_level.push(root);
        std::stack<TreeNode*> next_level;
        bool is_reverse = false;
        while (!this_level.empty()) {
            is_reverse = !is_reverse;
            std::vector<int> current_level_vals;
            while(!this_level.empty()) {
                TreeNode* q = this_level.top();
                this_level.pop();
                current_level_vals.push_back(q->val);
                if (is_reverse) {
                    if (q->left != nullptr) next_level.push(q->left);
                    if (q->right != nullptr) next_level.push(q->right);
                } else {
                    if (q->right != nullptr) next_level.push(q->right);
                    if (q->left != nullptr) next_level.push(q->left);
                }
            }
            this_level = std::move(next_level);
            next_level = std::stack<TreeNode*>{};
            result.push_back(current_level_vals);
        }
        return result;
    }
};
