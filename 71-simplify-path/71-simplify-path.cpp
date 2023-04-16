class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string result;


        for(int idx = 0; idx < path.size(); idx++)
        {
            if(path[idx] == '/') continue;
            string temp;

            while(idx < path.size() && path[idx] != '/' ){
                temp += path[idx];
                idx++;
            }

            if(temp == ".") continue;
            else if(temp == ".."){
                if(!st.empty())
                    st.pop();
            }
            else{
                st.push(temp);
            }
        }

        while(!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        }

        // if no directory or file is present
        if(result.size() == 0)
            return "/";

        
        return result;
    }
};