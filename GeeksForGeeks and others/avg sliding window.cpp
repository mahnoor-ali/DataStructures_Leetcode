vector<double> slidingWindowAverage(int a[], int n, int k) {
    vector<double> result;
    double sum = 0.0;
    int left = 0, right = 0;
    while (right < n) {
        sum += a[right];
        if (right - left + 1 == k) {
            result.push_back(sum / k);
            sum -= a[left];
            left++;
        }
        right++;
    }
    return result;
}
