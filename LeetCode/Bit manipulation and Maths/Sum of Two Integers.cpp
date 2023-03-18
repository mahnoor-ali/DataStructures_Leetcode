class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) // shifting the carry value to the left until it is 0, indicating that there is no more carry left. 
        {
            int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
// a&b is the carry -> if a&b is 0, then there is no carry left
// a^b is the sum without carry