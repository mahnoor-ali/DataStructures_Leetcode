// 217. Contains Duplicate

// NAIVE APPROACH.. NOT ACCEPTED DUE TO TIME LIMIT EXCEEDED
// Complexity: O(n^2)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0; i< nums.size(); i++)
        {
         for(int j=i+1; j< nums.size(); j++)
         {
            if ((nums[i]==nums[j])&&(i!=j))
            return true;
         }
        }
         return false;
    }
};


// USING UNORDERED MAP in STL
// increase the count of the element in the map. If an element is already present (i.e it's count is already 1 in the map), then return true
// Time Complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int, int> numsMap;
       for(int i=0; i<nums.size(); i++)
       {
           if(numsMap[nums[i]]==1)
            return true;
        numsMap[nums[i]]++;   
       }
       return false;
    }
};


// USING SET in STL
// compare size of set with size of vector. If size of vector > set then vector contains duplicate elements
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};