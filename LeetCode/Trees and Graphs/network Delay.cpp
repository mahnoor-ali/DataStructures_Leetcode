class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Set infinity to be a very large number
        const int inf = 1e9;
        // Define visited array and distance array
        bool vis[n+1]; // visited array to keep track of visited nodes
        int dis[n+1]; // distance array to store the minimum distance from source to each node
        // Initialize distance array and visited array
        for(int i=1; i<=n; i++){
          dis[i]=inf; // set all distances to infinity initially
          vis[i]=false; // mark all nodes as unvisited initially
        }
        // Define the priority queue to implement Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // Define adjacency list to store the graph
        vector<pair<int, int>> adj[n+1];
        // Fill the adjacency list with edges and weights
        for (auto t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        // Set distance of source node to be 0
        dis[k] = 0;
        // Push the source node into the priority queue
        q.push({0,k});
        // Implement Dijkstra's algorithm using priority queue
        while (!q.empty()) {
            // Pop the node with minimum distance from priority queue
            int v = q.top().second; 
            q.pop();
            // If the node has already been visited, continue to the next node
            if (vis[v])
             continue;
             // Mark the node as visited
             vis[v] = true;
             // Update distances of the neighbors of the node
             for (auto u : adj[v]) {
                 int b = u.first, w = u.second;
                 if (dis[v]+w < dis[b])
                  {
                    dis[b] = dis[v]+w;
                    // Push the updated distances and the corresponding node into the priority queue
                    q.push({dis[b],b});
                  }
             }  
         }
         // Find the maximum distance from the source to any other node
         int time = *max_element(dis+1, dis+n+1);
         // If any node is not reachable from the source node, return -1
         return time==inf? -1: time;
    }
};