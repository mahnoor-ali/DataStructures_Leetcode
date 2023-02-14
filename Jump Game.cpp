   /* Intuition: We start from the end of the array and check if we can reach the previous nearest index.
    If we can reach the previous index, we update the minJump to 0.
    If we can't reach the previous index, we increment the minJump.
    If we can reach the first index, we return true. Else, we return false.
    minJump=0 means succesful jump from the previous indices to the current index.
     */

    bool canJump(vector<int>& nums) {
        if(nums.size()==1) // If the array has only one element, we can always reach the end.
         return true;
        int minJump=-1; // minJump is the minimum number of jumps required to reach the current index.
        for(int i=nums.size()-1; i>=0; i-- ){
        minJump++;
        if(nums[i]>=minJump) 
          minJump=0;
        }
       if(minJump==0)
        return true;
       return false;
    }