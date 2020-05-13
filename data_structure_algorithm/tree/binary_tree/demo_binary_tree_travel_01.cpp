#include <iostream>
#include <list>

const int kNullLeafFlag = -9999999;

struct TreeNode 
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *create_tree_node(int value, TreeNode *left, TreeNode *right) 
{
    TreeNode *node  = new TreeNode;
    node->value     = value;
    node->left      = left;
    node->right     = right;
    
    return node;
}

void pre_order(TreeNode *root) 
{
    if (root) {
        std::cout<<root->value <<"\t";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(TreeNode *root) 
{
    if (root) {
        in_order(root->left);
        std::cout<<root->value <<"\t";
        in_order(root->right);
    }
}

void post_order(TreeNode *root) 
{
    if (root) {
        post_order(root->left);
        post_order(root->right);
        std::cout<<root->value <<"\t";
    }
}

void level_order(TreeNode *root) 
{
    std::list<TreeNode *> list;
    if (root) list.push_back(root);
    
    while(! list.empty()) {
        TreeNode *current = list.front();
        std::cout<<current->value <<"\t";
        if (current->left) list.push_back(current->left);
        if (current->right) list.push_back(current->right);
        list.pop_front();
    }
}

void destroy_tree(TreeNode **root) 
{
    if (root && *root) {
        destroy_tree(&((*root)->left));        
        destroy_tree(&((*root)->right));        
        delete *root;
        *root = nullptr;
    }
}

TreeNode *create_tree_level_order(const int array[], 
    TreeNode *root,
    const int index,
    const int len) 
{
    if (index < len) 
    { 
        if (kNullLeafFlag == array[index]) return nullptr;
        TreeNode* temp = create_tree_node(array[index], nullptr, nullptr); 
        root = temp; 
  
        // insert left child 
        root->left = create_tree_level_order(array, 
                   root->left, 2 * index + 1, len); 
  
        // insert right child 
        root->right = create_tree_level_order(array, 
                  root->right, 2 * index + 2, len); 
    } 
    return root;  
}

void Test_case_01_travel_tree() 
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 }; 
    int len = sizeof(arr)/sizeof(arr[0]); 
    TreeNode *root = nullptr;
    root  = create_tree_level_order(arr, root, 0, len); 
    std::cout<<"\nin order:" <<std::endl;
    in_order(root); 
    std::cout<<"\npre order:" <<std::endl;
    pre_order(root);
    std::cout<<"\npost order:" <<std::endl;
    post_order(root);
    std::cout<<"\nlevel order:" <<std::endl;
    level_order(root);
    destroy_tree(&root);
}

void Test_case_02_travel_tree() 
{
    int arr[] = { 8, 3, 10, 1, 6, kNullLeafFlag, 14, 
                  kNullLeafFlag, kNullLeafFlag, 4, 7, 
                  kNullLeafFlag, kNullLeafFlag, 13 }; 

    int len = sizeof(arr)/sizeof(arr[0]); 
    TreeNode *root = nullptr;
    root  = create_tree_level_order(arr, root, 0, len); 
    std::cout<<"\nin order:" <<std::endl;
    in_order(root); 
    std::cout<<"\npre order:" <<std::endl;
    pre_order(root);
    std::cout<<"\npost order:" <<std::endl;
    post_order(root);
    std::cout<<"\nlevel order:" <<std::endl;
    level_order(root);
    destroy_tree(&root);
}
int main(int argc, char* argv[]) 
{

    Test_case_01_travel_tree() ;
    Test_case_02_travel_tree() ;
    return 0;
}
