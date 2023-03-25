 int lenOfLongSubarr(int a[],  int N, int k) 
    { 
        int sum=0, maxSize=0, diff;
        map<int, int> m;
        m[0]=-1; //index i=-1 -> sum=0
        for(int i=0; i<N; i++)
        {
          sum+=a[i];
          diff = sum-k; //current sum - target value
          if(m.find(sum-k) != m.end()) //if difference is found -> sum-(sum-k)=k -> found!
              maxSize=max(maxSize, i-m[diff]); // i > m[diff]
          if(m.find(sum) == m.end())
              m[sum]=i;
        }
        return maxSize;
    } 