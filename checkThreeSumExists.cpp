// Using 2 pointer approach. lo,hi pointers at the beginning and end of list repectively
//For each element x of list, use 2 sum approach i.e find 'target-x' which will be sum of 2 distinct no.

bool threeSum(vector<int> arr, int target)
{
    bool isFound=false;
    int hi=arr.size()-1; //last index of array
    int lo = 1; // 1 index of array instead of 0 because we want distinct elements sum
    int sum=0;
    sort(arr.begin(), arr.end()); //O(nlogn)
    for (int i = 0; i < arr.size(); i++)
    {
        while (lo<hi) //until both indices meet
        {
            sum=arr[i]+arr[hi]+arr[lo];
            if(sum==target)
            { return true;
             }
            else if (sum<target)
            { lo++; }
            else
            { hi--; }            
        }
        
    }
    return isFound;
    
}