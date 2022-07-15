/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        
        function<void(TreeNode*)> realTraversal;
        realTraversal = [&](TreeNode* node){
            if (!node) return;
            if(node->left) realTraversal(node->left);
            values.push_back(node->val);
            if(node->right) realTraversal(node->right);
        };
        
        realTraversal(root);
        return values;
    }
};
