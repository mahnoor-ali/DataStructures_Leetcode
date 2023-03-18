//READ MY DETAILED EXPLANATION OF THIS PROBLEM AT: https://leetcode.com/problems/flip-string-to-monotone-increasing/solutions/3075287/dynamic-problem-easy-solution-o-n-time/
class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int flip_number = 0, ones_count = 0;
    for (int i = 0; i < S.length(); i++)
    {
    if (S[i] == '1')
      ones_count++;
    else{
      flip_number++;
      flip_number = min(flip_number, ones_count);
     }
    }
    return flip_number;
}
};

