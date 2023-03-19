/*
The given algorithm aims to traverse a 2D matrix in a spiral order and store the values in a 1D vector.
 To achieve this, four pointers are maintained to represent the boundaries of the matrix. The algorithm starts
  by traversing the top row, then the right column, followed by the bottom row, and finally the left column,
   while updating the corresponding boundary pointers. This process is repeated until all elements of the matrix 
   are visited.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
  
        vector<int> res;
        // t: top, b: bottom, l: left, r: right --> pointers to adjust boundary
        int t=0, b=matrix.size(); 
        int l=0, r=matrix[0].size(); 

    while(l<r && t<b)
      {
        //top row iteration
        for(int i=l; i<r; i++)
         res.push_back(matrix[t][i]);
        t++;

        //right column iteration
         for(int i=t; i<b; i++)
          res.push_back(matrix[i][r-1]); //r-1 -> last index
         r--;

         if(!(l<r && t<b)) //check condition after update of a row/ column (t,r or b,t)
           break;

        //bottom row iteration
         for(int i=r-1; i>=l; i--)
          res.push_back(matrix[b-1][i]); //b-1 ->last index
         b--;

        //left column iteration
         for(int i=b-1; i>=t; i--)
          res.push_back(matrix[i][l]);
         l++;
       }
       return res;
    }
};