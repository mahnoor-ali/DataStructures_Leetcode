class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxIndex = 1,  minIndex = 0;
        for(int i=1; i<prices.size(); i++)
        {            
        if((prices[minIndex] > prices[i])&&(i<maxIndex))
        {
            minIndex=i;  
            if((minIndex==maxIndex)&&(maxIndex!=prices.size()))
              maxIndex=minIndex+1;     
        } 
        else if((prices[minIndex] < prices[i])&&(prices[maxIndex]<prices[i])&&(i>maxIndex))
            maxIndex=i;
        }
        return prices[maxIndex]-prices[minIndex];
    }
};                           