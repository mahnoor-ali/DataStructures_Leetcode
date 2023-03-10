
int findDuplicateAndMissing(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int dup = -1, missing = -1;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i+1]) {
            dup = nums[i];
        } else if (nums[i+1] - nums[i] > 1) {
            missing = nums[i] + 1;
        }
    }
    // Handle edge case of missing number being at the end of the array
    if (nums[n-1] != n && missing == -1) {
        missing = n;
    }
    return dup + missing;
}