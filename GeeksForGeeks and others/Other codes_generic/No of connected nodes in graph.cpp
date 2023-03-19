/*
Initialize an empty set of visited vertices and a count of zero connected components.
For each vertex in the graph, if it has not been visited yet, increment the count of connected components, perform a DFS traversal starting from that vertex, and mark all visited vertices as visited.
For each unvisited neighbor of the current vertex, increment the count of connected components, perform a DFS traversal starting from that neighbor, and mark all visited vertices as visited.
When all vertices have been visited, the count of connected components will be equal to the number of times DFS was called. Return this count as the output.
This algorithm has a time complexity of O(V+E), where V is the number of vertices and E is the number of edges in the graph. The space complexity is also O(V+E), due to the use of the visited array and the graph data structure.
*/


//Given: vector<vector<int>> g
// for example: [[1,2],[0,2],[1,3],[2]]


 vector<bool> visited(n, false);
vector<vector<int>> g;
 int n = g.size();
void dfs( int vertex) {
    visited[vertex] = true;
    for (int child: g[vertex]) {
        if (visited[child])
            continue;
            dfs(child);
    }
}

int countComponents() {
    int count = 0;
    for (int i = 0; i < n; i++) //check for each node
     {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }
    return count;
}