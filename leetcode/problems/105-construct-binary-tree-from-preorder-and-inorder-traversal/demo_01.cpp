/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 
                0, preorder.size(),
                0, inorder.size());
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_begin, int pre_end, int in_begin, int in_end) {

        TreeNode *root = nullptr;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        if (pre_begin == pre_end || in_begin == in_end) return root;

        int root_value = preorder[pre_begin];
        int root_in_pos = in_begin;

        for ( ; root_in_pos  < in_end; ++root_in_pos) {
            if (inorder[root_in_pos] == root_value) break;
        }

        int left_node_count = root_in_pos - in_begin;

        int left_pre_begin = pre_begin + 1;
        int left_pre_end   = pre_begin + left_node_count + 1;
        int left_in_begin = in_begin;
        int left_in_end = root_in_pos;

        int right_pre_begin = left_pre_end;
        int right_pre_end   = pre_end;
        int right_in_begin = root_in_pos + 1;
        int right_in_end = in_end;

        left = buildTree(preorder, inorder, 
                left_pre_begin, left_pre_end,
                left_in_begin, left_in_end);

        right = buildTree(preorder, inorder, 
                right_pre_begin, right_pre_end,
                right_in_begin, right_in_end);
        root = new TreeNode(root_value, left, right);

        return root;
    }

    TreeNode* buildTreeBad(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        if (preorder.empty()) return root;
        if (inorder.empty()) return root;

        int root_value = preorder[0];

        vector<int> left_preorder;
        vector<int> right_preorder;
        vector<int> left_inorder;
        vector<int> right_inorder;

        auto in_iter = std::find(inorder.begin(), inorder.end(), root_value);
        for (auto iter = inorder.begin(); iter != in_iter; ++iter) {
            left_inorder.push_back(*iter);
        }
        
        for (auto iter = (in_iter + 1); iter != inorder.end(); ++iter) {
            right_inorder.push_back(*iter);
        }

        for (auto iter = preorder.begin(); iter != preorder.end(); ++iter) {
            auto left_iter = std::find(left_inorder.begin(), left_inorder.end(), *iter);
            if (left_iter != left_inorder.end()) { 
                left_preorder.push_back(*iter);
                continue;
            }
            auto right_iter = std::find(right_inorder.begin(), right_inorder.end(), *iter);
            if (right_iter != right_inorder.end()) {
                right_preorder.push_back(*iter);
                continue;
            }
        }


        left = buildTree(left_preorder, left_inorder);
        right = buildTree(right_preorder, right_inorder);
        root = new TreeNode(root_value, left, right);

        return root;
    }
};


int main (int argc, chari *argv[]) 
{
    return 0;
}
