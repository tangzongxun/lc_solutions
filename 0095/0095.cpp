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
    vector<TreeNode*> gen(int start, int end){
        if (start == end){
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> treevec;
        for (int i = start; i < end; i++){
            auto left = gen(start, i);
            auto right = gen(i+1, end);
            for (auto l: left){
                for (auto r: right){
                    auto root = new TreeNode{i};
                    root->left = l;
                    root->right = r;
                    treevec.push_back(root);
                }
            }
        }
        return treevec;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0){
            return vector<TreeNode*>{};
        }
        return gen(1, n+1);
    }
};
