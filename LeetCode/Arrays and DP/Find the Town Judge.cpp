//time complexity: O(n)
//space complexity: O(n)
//find detailed solution here: https://leetcode.com/problems/find-the-town-judge/solutions/3099543/easy-efficient-hash-map-solution-o-n/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       if(n==1)
         return 1;
        unordered_map<int, int[2] > umap; // first index-> no of trusts gained by "key" , second index-> it trusts someone:1
       for (const auto& t: trust) {
        umap[t[1]][0]++; //b is trusted, increment no of trusts for b in the map
        umap[t[0]][1]=1; //trust[i][0]-> 'a' trusts b:1 ->true
    }
       for (const auto& t: trust) {
         if((umap[t[1]][0] == n-1) && (umap[t[1]][1]==0))
            return t[1];
           }
        return -1;
    }
};