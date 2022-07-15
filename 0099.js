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
 * @return {void} Do not return anything, modify root in-place instead.
 */

let swapNode = (a, b) => {
    t = a.val;
    a.val = b.val;
    b.val = t;
}

let recoverTree = root => {
    let elem1 = null, elem2 = null;
    let prev = new TreeNode(Number.NEGATIVE_INFINITY);
    let travel = root => {
        if (root === null) return;
        travel(root.left);
        if (root.val < prev.val) {
            if (elem1 === null) {
                elem1 = prev;
            }
            elem2 = root;
        }
        prev = root;
        travel(root.right);
    }
    travel(root);
    swapNode(elem1, elem2);
}
