//Related Topics: Hash Table, Strings


class Solution {
public:
    int romanToInt(string s) {
        int sum = symbols[s[s.size()-1]]; // adding last element as it will always be summed
        unordered_map<char, int> symbols = {  { 'I' , 1 },
                                              { 'V' , 5 },
                                              { 'X' , 10 },
                                              { 'L' , 50 },
                                              { 'C' , 100 },
                                              { 'D' , 500 },
                                              { 'M' , 1000 } };
        for(int i=0; i<s.size()-1; i++)        {
            if(symbols[s[i]]<symbols[s[i+1]]){
                sum -= symbols[s[i]];
            }
            else{
                sum += symbols[s[i]];
            }
        }
        return sum;
    }
};