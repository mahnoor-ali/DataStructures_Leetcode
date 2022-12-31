// 53. Maximum Subarray

//Time complexity: O(n)
#include <algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int startIndex, endIndex;
        int maxSum = nums[0], currSum = nums[0];
        for(int i=1; i< nums.size(); i++)
        {
            if(currSum > 0)
            {
                currSum+=nums[i];
            }
            else
            {
                currSum=nums[i];
                startIndex=i;
            }
            if(currSum>maxSum)
            {
            maxSum=currSum;
            endIndex=i;
            }

        }
        cout << "Max Sum: " << maxSum << " |  Start Index: " << startIndex << " End Index: " << endIndex << endl;
        return maxSum;
    }
};

//OR---

int max_subarray_sum(int nums[], int n) {
  int max_sum = nums[0];
  int curr_sum = nums[0];
  for (int i = 1; i < n; i++) {
    curr_sum = max(nums[i], curr_sum + nums[i]);
    max_sum = max(max_sum, curr_sum);
  }
  return max_sum;
}
