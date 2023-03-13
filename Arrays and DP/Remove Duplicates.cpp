/* Approach: Two Pointer
 Time Complexity: O(n)
 Space Complexity: O(1)
 Traverse the array and only copy the current element unique element to the next position of the array.
*/

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int j=0, i, n = nums.size();
        for(i=0; i<n-1; i++)
        {
            if(nums[i]!=nums[i+1])
              nums[j++]=nums[i];
        }
        nums[j++]=nums[i];
        return j;       
    }
};