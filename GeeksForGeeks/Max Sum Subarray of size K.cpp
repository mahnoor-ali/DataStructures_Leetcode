long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i=0, cornerElem=0;
        long sum=0, maxSum=0;
        for(int j=0; j<N; j++)
        {
            sum += Arr[j];
            if(j-i+1 == K)
            {
                sum-=cornerElem;
                maxSum=max(maxSum, sum);
                cornerElem=Arr[i++];
            }
        }
        return maxSum;
    }