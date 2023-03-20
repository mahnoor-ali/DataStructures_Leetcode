// ITERATIVE SOLUTION
int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end)
        {
            mid= start + (end-start)/2;
            if(nums[mid]==target)
             return mid;
            if(target<nums[mid])
             end=mid-1;
            else if (target>nums[mid])
             start=mid+1;
        }
        return -1;
    }

// RECURSIVE SOLUTION
int binarySearch(vector<int>& nums, int x, int start, int end) {
  if (end >= start) {
    int mid = start + (end - start) / 2;

    // If found at mid, then return it
    if (nums[mid] == x)
      return mid;

    // Search the left half
    if (nums[mid] > x)
      return binarySearch(nums, x, start, mid - 1);

    // Search the right half
    return binarySearch(nums, x, mid + 1, end);
  }

  return -1;
}