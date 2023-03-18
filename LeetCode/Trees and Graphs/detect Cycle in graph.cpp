class Solution {
  public:
  vector<bool> vis;
   bool dfs(int v, int par, bool vis[], vector<int> adj[])
   {
       vis[v]=true;
       bool isCycle= false;
       for(int child: adj[v]) //visit all children of vertex v
       {
            if(par==child && vis[child])
              continue;
            if(vis[child]) 
              return true;
           isCycle |= dfs(child, v, vis, adj);
       }
       return isCycle;
   }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
          bool vis[V]={false};
          for(int i=0; i<V; i++){
              if(vis[i])
               continue;
              if(dfs(i,-1,vis,adj))
               return true;
          }
          return false;
    }
};