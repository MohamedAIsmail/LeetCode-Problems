class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());

        int ctr = 0;
        while (j > i)
        {
            if (nums[i] + nums[j] == k)
            {
                i++;
                j--;
                ctr++;
            }
            else if (nums[i] + nums[j] > k)
            {
                j--;
            }
            else{
                i++;
            }
        }

        return ctr;
    }
};