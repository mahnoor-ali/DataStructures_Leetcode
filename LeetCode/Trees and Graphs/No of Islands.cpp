//Initial Approch: was using visited array to keep track of visited nodes, but it was taking extra space and time.
// Final Approch: Using the grid itself to keep track of visited nodes. If the node is visited, then change it to '0' and then do dfs on its neighbours.
// Calling dfs on 4 neighbours of the current node. If the node is visited, then return. If the node is not visited, then change it to '0' and then do dfs on its neighbours.

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') {
            return;
        }
        grid[i][j]='0';
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
