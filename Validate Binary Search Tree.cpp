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
   bool isValidBST(TreeNode* root) {
       if(root==NULL || (root->left == NULL && root->right == NULL) )
           return true;

        else if (!(root->right) && root->left)
        {
            if(root->val <= root->left->val) 
              return false;
        }

        else if ( root->right && !(root->left))
        {
            if(root->val > root->right->val) 
              return false;
        }

        else if((root->val <= root->left->val) || (root->val >= root->right->val))
          return false;

        else if((root->val == root->left->val) && (root->val == root->right->val))
          return false;

        return isValidBST(root->left) && isValidBST(root->right);
        return true;
    }
};