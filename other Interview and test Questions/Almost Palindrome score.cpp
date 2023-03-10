int almost_palindrome_error_score(std::string s) {
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - i - 1]) {
            count += 2;
        }
    }
    if (count <= 1) {
        return 0;
    }
    else {
        return count - 1;
    }
}
