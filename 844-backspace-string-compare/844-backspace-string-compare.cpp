class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> stS, stT;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#' && !stS.empty())
                stS.pop();
            else if (s[i] != '#')
                stS.push(s[i]);
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#' && !stT.empty())
                stT.pop();
            else if (t[i] != '#')
                stT.push(t[i]);
        }

        if (stS == stT)
            return true;
        else
            return false;
    }
};