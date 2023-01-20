//add elements to the adjacency matrix by input in one go
void addNodes()
{
    int x, y; //node x connected to node y 
    int nodesCount, edgesCount;
    cin >> nodesCount >> edgesCount;

    for (int i = 0; i < edgesCount; i++) //iterate loop edgesCount times instead of nodeCount to find all the connections including cycles bw nodes 
    {
        cin >> x >> y;
        //save connection in both forms: x to y , y to x
        adjMatrix[x].push_back(y);
        adjMatrix[y].push_back(x);
    }
}

void dfs(int node) {
    cout << node << " ";
    visited[node] = true;
    for (int i = 0; i < N; i++) {
        if (adjMatrix[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}



