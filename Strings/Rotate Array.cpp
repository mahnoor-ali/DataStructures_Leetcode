/* INEFFICIENT: Time Limit Exceeded
Time:O(n^2) 
Space: O(1)  */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // handle the case when k is greater than n
        
        while (k > 0) {
            int temp = nums[n-1];
            for (int i = n-2; i >= 0; i--) {
                nums[i+1] = nums[i];
            }
            nums[0] = temp;
            k--;
        }
    }
};

/*
EFFICIENT: Time: O(n) Space: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), temp;
        k = k % n; // handle the case when k is greater than n
            for (int i = 0; i < n/2; i++){ //reverse whole array
                temp=nums[i];
                nums[i] = nums[n-i-1];
                nums[n-i-1] = temp;
            }
            for (int i = 0; i < k/2; i++){ //reverse first k elements
                temp=nums[i];
                nums[i] = nums[k-i-1];
                nums[k-i-1] = temp;
            }  
            for (int i = k, j=0; j < (n-k)/2; i++, j++) { //reverse last n-k elements
                temp=nums[i];
                nums[i] = nums[n-j-1];
                nums[n-j-1] = temp;
            }                 
    }
};
