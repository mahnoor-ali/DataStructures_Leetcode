class Solution {
    
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int source, int destination)
    {
        if(visited[source]) 
          return false;
        if(destination==source)
          return true;
        visited[source]=true;
        for(int i=0; i<adj[source].size(); i++)
        {
            if(dfs(adj, visited, adj[source][i], destination))
             return true;
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto v: edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n,0);
        return dfs(adj, visited, source, destination);
    }

};

// -----------------------

// BFS Solution

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> adj(n);
    for(auto v: edges)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == destination)
            return true;
        for(int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}
