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
    TreeNode* Current;
    void Inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        Inorder(root->left);
        Current->right = root;
        root -> left = nullptr;
        Current = root;

        Inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        Current = dummy;
        Inorder(root);
        return dummy->right;
        
    }
};