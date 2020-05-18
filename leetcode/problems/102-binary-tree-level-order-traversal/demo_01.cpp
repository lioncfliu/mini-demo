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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_list;
        dep_order(root, 0, level_list);
        return level_list;
    }
    void dep_order(TreeNode *root, int depth, vector<vector<int> > &level_list) {
        if (! root ) return ;
        if (depth >= level_list.size()) level_list.push_back(vector<int>(0));
        level_list[depth].push_back(root->val);
        dep_order(root->left, depth + 1, level_list);
        dep_order(root->right, depth + 1, level_list);

    }
    // bad , can not handle it while it rollback to list
    void level_order(TreeNode *root, vector<vector<int> > &level_list) {
        if (! root) return ;
        int node_counter = 0;
        int last_level = 0;
        int curr_level = 0;
        deque<TreeNode *> queue;
        queue.push_back(root);
        level_list.push_back(vector<int>{});
        while (! queue.empty()) {
            ++node_counter;
            curr_level = log2(node_counter);
            TreeNode * node = queue.front();
            if (node) {
                if (curr_level != last_level) {
                    last_level = curr_level;
                    level_list.push_back(vector<int>{});
                }
                level_list[last_level].push_back(node->val);
                queue.push_back(node->left);
                queue.push_back(node->right);
            }
            queue.pop_front();
        }
    }
};


int main(int argc, char* argv[]) 
{
    return 0;
}
