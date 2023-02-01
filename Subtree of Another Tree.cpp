/*
The approach here is to first compare the root nodes of the first and second trees using the isSameTree function.
 If they match, return true. If not, check if the second tree is a subtree of either the left or right child of the first tree.
  Repeat this process recursively until the entire first tree has been checked, or the second tree has been found to be a subtree.
*/


class Solution {
private:
int subrootVal;
public:
  
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p&&!q || q&&!p)
          return false;
        if(p && q){
            if(p->val != q->val){
               return false;     
          }}
        if(!p && !q)
         return true;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);         
    }    

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == NULL) return false;
    if(isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

};