// Sort array
// check if two consecutive numbers are same using BITWISE XOR
// if not found, last element is the single instance number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1; i+=2)
        {
            cout << nums[i];
            if(nums[i]^nums[i+1])
             return nums[i];
        }
        return nums[nums.size()-1];
    }
};