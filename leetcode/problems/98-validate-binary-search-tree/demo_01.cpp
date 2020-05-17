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
    bool isValidBST(TreeNode* root) {
        if (! root) return true;
        return is_bst(root, LONG_MIN , LONG_MAX);
    }
    void in_order(TreeNode *root, vector<int> &in_order_list) {
        if (root) {
            in_order(root->left, in_order_list);
            in_order_list.push_back(root->val);
            in_order(root->right, in_order_list);
        }
    }
    bool is_bst(TreeNode *root) {
        vector<int> in_order_list;
        in_order(root, in_order_list);
        for (int i = 0; i < in_order_list.size() - 1; i++) {
            if (in_order_list[i] >= in_order_list[i+1]) return false;
        }
        return true;
    }

    bool is_bst(TreeNode *root, const long long &min, const long long &max) {
        if (! root) return true;
        if (root->val <= min || root->val >= max) return false;
        return is_bst(root->left, min, root->val) && is_bst(root->right, root->val, max);
    }
};

int main(int argc, char* argv[]) 
{
    return 0;
}
