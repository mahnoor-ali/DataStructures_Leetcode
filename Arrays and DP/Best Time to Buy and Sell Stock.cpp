    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP=0, l=0; //left pointer
        for(int r=1; r<n; r++)
        {
            //if left value is greater than right value it means, buy value>sell value -> which is not desired, so we won't be buying at 'l' day
            if(prices[l]>prices[r])
             l=r; //move l to new smallest, since r has passed through all the numbers bw l ---> r
            else
             maxP = max(maxP, prices[r]-prices[l]);
        }
        return maxP;
    }