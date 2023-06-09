class Solution {
public:
    void moveZeroes(vector<int> &nums)
    {
        int numZeros = 0, temp = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                numZeros++;
                continue;
            }
            else if (numZeros > 0)
            {
                nums[i - numZeros] = nums[i];
                nums[i] = 0;
            }
        }
    }
};