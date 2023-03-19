class Solution {
public:
    bool isValid(string s) {
         if(s.length()==1)
          return false;
         stack<char> st;
         for(auto b : s)
         {
             if(b=='{' || b=='(' || b=='[')
              st.push(b);
             else if(!st.empty() && ((b=='}' && st.top()=='{')||(b==')' && st.top()=='(') || (b==']' && st.top()=='[')))
               st.pop();
             else
               return false;
         }
         return st.empty();
    }
};