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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (! s && ! t) return true;
        if (! s || ! t) return false;

        if (check_left_right_equality(s, t)) return true;
        if (isSubtree(s->left, t)) return true;
        if (isSubtree(s->right, t)) return true;

        return false;
    }
    bool check_left_right_equality(TreeNode *left, TreeNode *right) {
        if (! left && ! right) return true;
        if (! left || ! right) return false;

        if (left->val == right->val 
            && check_left_right_equality(left->left, right->left)      
            && check_left_right_equality(left->right, right->right))
            return true;

        return false;
    }
};


int main(int argc, char* argv[]) 
{
    return 0;
}
