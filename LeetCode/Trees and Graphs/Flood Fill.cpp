//BFS is better than DFS in this case

// USING DFS ALGORITHM 
class Solution {
public:
 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color, int m, int n, int x)
    {
        if((sr<m && sr>=0) && (sc<n && sc>=0))
        {
            if(image[sr][sc]==x)
            {
                image[sr][sc] = color;
                floodFill(image, sr+1, sc, color, m, n, x);
                floodFill(image, sr, sc+1, color, m, n, x);
                floodFill(image, sr-1, sc, color, m, n, x);
                floodFill(image, sr, sc-1, color, m, n, x);
            }
        }
         return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if(color==image[sr][sc])
          return image;
        
        int x = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        return floodFill(image, sr, sc, color, m, n, x);
    }
};

//-------------------------------------------------------------

//Using BFS Algorithm
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        if(color==oldColor)
          return image;
        
        vector<vector<int>> visited (m, (vector<int>(n,0)));
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            if(r>=m || r<0 || c>=n || c<0 || oldColor!=image[r][c] || visited[r][c])
              continue;
            
            visited[r][c]=1;
            image[r][c]= color;

            q.push({r,c+1});
            q.push({r+1,c});
            q.push({r,c-1});
            q.push({r-1,c});
        }        
        return image;
    }
};