class Solution {
public:
// Using 2 pointer approach. lo,hi pointers at the beginning and end of list repectively
//For each element x of list, use 2 sum approach i.e find 'target-x' which will be sum of 2 distinct no. So, as a whole it makes up 3 numbers' sum
    vector<vector<int>> threeSum(vector<int>& nums)
    {
    vector<vector<int>> triplets;
    int hi, lo, sum=0;
    sort(nums.begin(), nums.end()); //O(nlogn)
    for (int i = 0; i < nums.size(); i++)
    {
        lo=i+1;
        hi=nums.size()-1;
        while (lo<hi) //until both indices hi, lo meet
        {
            sum=nums[i]+nums[hi]+nums[lo];
            if(sum==0)
            { 
               triplets.push_back({nums[i], nums[hi], nums[lo]});
               lo++;
               hi--;
            }
            else if (sum<0)
            { lo++; }
            else
            { hi--; }            
        }
    }
    //use a set to store the triplets, as a set does not allow duplicate elements.
     set<vector<int>> s(triplets.begin(), triplets.end()); 
     triplets.assign(s.begin(), s.end());
    return triplets;
    }
};