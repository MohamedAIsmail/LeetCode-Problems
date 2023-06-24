class Solution {
public:
    string reverseWords(string s)
    {
        vector<string> arr;
        string temp, result;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] == ' ' && temp != ""))
            {
                arr.push_back(temp);
                temp = "";
            }
            else if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                temp = temp + s[i];
            }
        }

        if (temp != "")
            arr.push_back(temp);

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (i > 0)
            {
                result = result + arr[i] + " ";
            }
            else
            {
                result = result + arr[i];
            }
        }

        return result;
    }
};