// 53. Maximum Subarray

//Time complexity: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = nums[0];
        for(int i=1; i< nums.size(); i++)
        {
            if(currSum > 0)
            {
                currSum+=nums[i];
            }
            else
                currSum=nums[i];
            if(currSum>maxSum)
            maxSum=currSum;
        }
        return maxSum;
    }
};