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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if root == p or == q return root
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        //if p and q < root, go to left subtree
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        //if p and q > root, got to right subtree
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p ,q);
        }
        //if root between p and q, return root
        return root;
        
    }
};
