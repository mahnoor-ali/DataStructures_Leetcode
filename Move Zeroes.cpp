//Least to most efficient solutions
// (least efficient) solution 1 -> solution 2 -> solution 3 (most efficient)


// O(n^2)
// Selection sort

 void moveZeroes(vector<int>& nums) {
        int s=nums.size(), temp;
     for(int i=0; i<s; i++)
     {
        for(int j=i+1; j<s; j++)
        {
             if(nums[i]!=0)
               break;
            if(nums[i]==0 && nums[j]!=0)
            {
                temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }            
        }
     }   
    }


// O(n)
// Shift non-zero values as far forward as possible and Fill remaining space with zeros
class Solution {
public:
 void moveZeroes(vector<int>& nums) {
    int insertPos = 0;
    for (int num: nums) {
        if (num != 0) nums[insertPos++] = num;
    }        

    while (insertPos < nums.size()) {
        nums[insertPos++] = 0;
    }
} };


// O(n)
// Two pointer approach

 void moveZeroes(vector<int>& nums) {
        int s=nums.size(), temp;
     for(int i=0, j=0; i<s; i++)
     {
        if(nums[i]!=0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
     }   
 }
