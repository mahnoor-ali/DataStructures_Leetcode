// 1. Two Sum

//Time Complexity: O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indexStore;
        indexStore.insert(pair<int,int>(target - nums[0], 0));
        vector<int> sumsIndices;
        for(int i=1; i<nums.size(); i++)
        {
            if(indexStore.find(nums[i]) != indexStore.end())
            {
             sumsIndices.push_back(i); //endIndex
             sumsIndices.push_back(indexStore[nums[i]]); //startIndex
             break;
            }
            else
             indexStore.insert(pair<int,int>(target - nums[i], i));
        }
        return sumsIndices;
    }
};