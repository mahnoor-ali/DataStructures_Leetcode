#include <queue>
#include <list>
#include <iostream>
using namespace std;

// Constraints:
//1 <= V, E <= 104

int main()
{
	const int N = 10000;
    vector<int> adjMatrix[N]; // adjacency Matrix of graph 
    list<int> bfsOutput; // adjacency Matrix of graph 
    queue<int> explorationQueue; //stores nodes that are to be explored
    vector<bool> visited; //visited nodes status
    visited.resize(N, false);

    int startNode;
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

    cout << "start node: ";
    cin >> startNode;

    explorationQueue.push(startNode);
    visited[startNode] = true;
    bfsOutput.push_back(startNode);

    while (!explorationQueue.empty())
    {
        int node = explorationQueue.front();
        cout << node;
        //bfsOutput.push_back(node);
        explorationQueue.pop();
		
        for (int currNode : adjMatrix[node])
        {
            if (!visited[currNode])
            {
                explorationQueue.push(currNode);
                visited[node] = true;
            }
        }
    }
}

//Input format:
// 1st line: nodesCount, edgesCount
// next lines: each line contains 2 nodes that are connected
/*
Example:
7 7
1 2
1 3
2 4
2 5
3 6
3 7
4 5
*/
