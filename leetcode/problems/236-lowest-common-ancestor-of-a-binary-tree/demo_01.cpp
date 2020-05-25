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
    /// find p and q in root.
    /// 1. return root if root was nullptr.
    /// 2. if p or q in root ,then return one of both.
    /// 3. if both of p and q exist in root, the root is the commot parent
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /// nothing in nullptr
        if (! root) return nullptr;

        /// found p
        if (root == p) return root;
        /// foudd q
        if (root == q) return root;

        /// fond nothing ,then find p and q in children
        TreeNode *left =  lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        /// found p or q in right
        if (! left) return right;

        /// found p or q in left;
        if (! right) return left;

        /// found p and q in children of root
        if (right && left) return root;

        /// found nothing
        return nullptr;
    }
};
