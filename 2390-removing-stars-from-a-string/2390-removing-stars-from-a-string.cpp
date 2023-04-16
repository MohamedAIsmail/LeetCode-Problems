class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string result = "";
        for(int i = 0 ; i < s.size() ; i++){

            if(s[i] == '*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;

    }
};