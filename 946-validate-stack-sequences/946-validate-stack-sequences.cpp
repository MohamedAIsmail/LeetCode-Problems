class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;

        for (int idx = 0; idx < pushed.size(); idx++)
        {
            st.push(pushed[idx]);
            while (!st.empty() && st.top() == popped[0])
            {
                st.pop();
                popped.erase(popped.begin());
            }
        }

        if (!st.empty())
            return false;
        return true;
    }
};