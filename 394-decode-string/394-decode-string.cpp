class Solution {
public:
    string decodeString(string s)
    {
        stack<string> chars;
        stack<int> nums;
        int num = 0;
        string result = "";

        for (auto c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - 48);
            }
            else if(isalpha(c)){
                result += c;
            }
            else if(c == '['){
                chars.push(result);
                nums.push(num);
                result = "";
                num = 0;
            }
            else if(c == ']'){
                string temp = result;
                for (int i = 0; i < nums.top() - 1; i++){
                    result += temp;
                }
                result = chars.top() + result;
                chars.pop();
                nums.pop();
            }
        }
        return result;
    }
};