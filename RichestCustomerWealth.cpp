class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts)
     {
        int size = accounts.size(), max = 0;
        for(int i=0; i<size; i++) //sum of money of each person stored in first index of each row
        {
         accounts[i][0] = accumulate(accounts[i].begin(),accounts[i].end(), 0);
        }
        for(int j=0; j<size; j++) //finding max value i.e. richest person's wealth
        {
            if(accounts[j][0] > max)
              max = accounts[j][0];
        }
        return max;
    }
};