class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
    int maxProd = nums[0],minProd = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],maxProd*nums[i],minProd*nums[i]});
        minProd = min({nums[i],maxProd*nums[i],minProd*nums[i]}); //minP
        maxProd = temp;
        result = max(result,maxProd);
    }
    return result;
    }
};
/*
Maintains two variables, maxProd and minProd, which represent the maximum and minimum products uptill the current element, respectively. It also maintains a result variable to keep track of the overall maximum product found so far.
In each iteration, it updates the result variable to be the maximum of the result so far and maxProd(max product).
*/