/* function TreeNode(x) {
    this.val = x;
    this.left = null;
    this.right = null;
} */
function HasSubtree(r1, r2) {
    if (!r1 || !r2) return false
    return test(r1, r2) || HasSubtree(r1.left, r2) || HasSubtree(r1.right, r2)
}

function test(r1, r2) {
    if (!r2) return true
    if (!r1) return false
    return r1.val === r2.val && test(r1.left, r2.left) && test(r1.right, r2.right)
}