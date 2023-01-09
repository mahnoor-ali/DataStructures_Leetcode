//Efficient --> less lines of code (Complexity: O(n))

class Solution {
public:
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true; //to track if the array is increasing or decreasing

        for (int i = 0; i < A.size() - 1; ++i) {
            // Update the increment, decrement variables at each iteration
            inc &= A[i] <= A[i + 1];
            dec &= A[i] >= A[i + 1];
        }
        // Return true if the array is either increasing or decreasing
        return inc || dec;
    }
};


/*
This
from
this
 |
 |
 |
 v     */


//INEFFICIENT --> more lines of code (Complexity: O(n))
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int numsSize=nums.size(); // save it to avoid multiple calls in functions
        if (numsSize <= 1) return true;

        int start = 0, end = 1;
        for (int i = 0; i < numsSize - 1; i++)
        {
        bool isIncreasing = nums[start] < nums[end];
        bool isDecreasing = nums[start] > nums[end];
        if(nums[0] == nums[1] && numsSize>2)
        {
            isIncreasing = nums[1] < nums[2];
            isDecreasing = nums[1] > nums[2];
        }
        else if(nums[0] == nums[1] && numsSize==2)
         return true;
        }

        for (int i = 0; i < numsSize - 1; i++) {
            bool currentIncreasing = nums[i] <= nums[i + 1];
            bool currentDecreasing = nums[i] >= nums[i + 1];

            cout << "currentIncreasing , isIncreasing:";
            cout << currentIncreasing << isIncreasing;
            if (isIncreasing && !currentIncreasing)
              return false;
            if (isDecreasing && !currentDecreasing)
              return false;
        }

        return true;
    }
};
