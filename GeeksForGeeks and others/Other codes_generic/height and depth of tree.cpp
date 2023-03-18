/*
---SUMMARY:

 Section labelled as:
  1, 2 --> Neechy janay waly hn.. yani in mein hm tree me oper se nechy child ki taraf ja rhy hoty hn..
  3, 4 --> Uper janay waly hn.. yani in mein hm tree me nechy se oper parent ki taraf ja rhy hoty hn, qk recursion s wapsi ho re hoti h..
  as noted, depth is calculated as we go down the tree, and height is calculated as we come back up the tree. So placing them accordingly in section 2->depth, 3->height 
*/

vector <int> g[N];
bool vis[N];
int depth[N];
int height[N];
void dfs(int vertex)
{
  //1. if(vis[vertex]) return; // alternate of if condition in the for loop
  cout << vertex << " ";
  vis[vertex] = true; // mark the vertex as visited so that we don't visit it again
  for(int child: g[vertex])
  {
    if(vis[child]) continue; // if the child is already visited, then skip it
   //2 take action on child before entering its child node
    depth[child]=depth[vertex]+1;
    dfs(child);
    //3 take action on child after coming back from the child node
    height[vertex]=max(height[vertex],height[child]+1); //height of a vertex is the maximum height of its children + 1. arg1 height of vertex so far, arg2 height of curent child + 1
  }
  // take action on vertex before exiting the vertex
}

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i=1; i<=n; i++){
        cout << depth[i] << " " << height[i] << endl;
    }

}