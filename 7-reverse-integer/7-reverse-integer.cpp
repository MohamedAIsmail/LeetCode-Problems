class Solution
{
public:
    int reverse(int x)
    {
        string result;
        if (x > 0)
            result = "";
        else if (x < 0)
            result = "-";
        else
            return 0;

        while (x)
        {
            result = result + to_string(abs(x) % 10);
            x /= 10;
        }

        try
        {
            unsigned long sol = stoi(result);
            return sol;
        }
        catch (const std::out_of_range &e)
        {
            return 0; // or return an error message
        }
    }
};