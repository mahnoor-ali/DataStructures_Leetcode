vector <int> g[N];
int subtreeSum[N];
int evenNodesCount[N];

void dfs(int vertex)
{
//1.  take action on vertex after entering the vertex
vertex%2==0? evenNodesCount[vertex]=1 : evenNodesCount[vertex]=0;
subtreeSum[vertex] = vertex; //initially, the subtree sum of a vertex is 1 (itself)
  for(int child: g[vertex])
  {
   //2. take action on child before entering the child node
   dfs(child);
   //3. take action on child after coming back from the child node
    subtreeSum[vertex] += subtreeSum[child]; //add the subtree sum of the child to the subtree sum of the parent
    evenNodesCount[vertex] += evenNodesCount[child]; //add the even nodes count of the child to the even nodes count of the parent
  }
  //4. take action on vertex before exiting the vertex
}