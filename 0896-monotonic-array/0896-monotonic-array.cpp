class Solution {
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool ltr;
        if (nums.size() == 1)
            return true;
        if (nums[0] > nums[nums.size() - 1])
            ltr = false;
        else
            ltr = true;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (ltr)
            {
                if (nums[i] > nums[i + 1])
                    return false;
            }
            else
            {
                if (nums[i] < nums[i + 1])
                    return false;
            }
        }

        return true;
    }
};