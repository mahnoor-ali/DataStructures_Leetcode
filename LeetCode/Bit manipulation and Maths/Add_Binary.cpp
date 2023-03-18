class Solution {
public:
    string addBinary(string a, string b) {
        int aLen= a.length(), bLen = b.length();
        int n = max(aLen, bLen);
        int aBit, bBit, carry=0, sum=0;
        string result="";
        for(int i=0; i<n; i++)
        {
            aBit=i>=aLen? 0: a[aLen-i-1]-'0';
            bBit=i>=bLen? 0: b[bLen-i-1]-'0';
            sum = aBit + bBit + carry;
            result = char(sum%2 + '0') + result;
            carry = sum/2; 
        }
        if(carry) //add remaining carry, if any
         result = '1' + result;
         return result;
             }
};