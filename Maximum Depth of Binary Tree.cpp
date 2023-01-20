class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
           return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right)); 
    }
};

//View my explained solution at: https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/3083094/2-lines-easy-solution-recursion/