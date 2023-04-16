class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  //taking stack for keep tracking the order of the brackets..

        for(auto c : s)  //iterate over each and every elements
        {
            if( c == '(') st.push(')');
            else if(c == '[') st.push(']');
            else if(c == '{') st.push('}');
            else if(st.empty() || st.top() != c) {
                return false;
            }
            else if(st.top() == c) st.pop();
        }
        return st.empty(); 
    }
};