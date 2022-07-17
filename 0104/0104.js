/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

let max = a => b => a > b ? a : b;

let maxDepth = root => {
    if (root === null) return 0;
    return max(maxDepth(root.left))(maxDepth(root.right)) + 1;
}
