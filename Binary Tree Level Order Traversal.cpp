// complexity: O(V+E) -> O(n) where n is number of nodes in the graph, E is ignored..
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
         return ans;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while(!q.empty()) //to traverse all nodes ->until queue is empty
        {
            vector<int> level; //will be used to push in answer 2D vector
            n = q.size(); 
            for(int i=0; i<n; i++) //traverse all children of a node (n child, n <=2 )
            {
                TreeNode* node = q.front(); //get front node and visit its child
                q.pop();
                level.push_back(node->val); //push node to answer that is popped from queue
                if(node->left)
                  q.push(node->left);
                if(node->right)
                  q.push(node->right);
            }
            ans.push_back(level); //push array of ith level nodes
        }
        return ans;
    }
};