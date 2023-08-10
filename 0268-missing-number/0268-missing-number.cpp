class Solution {
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int normalSummation = 0, arraySummation = 0;
        for (int i = 1; i <= n; i++){
            normalSummation += i;
            arraySummation += nums[i - 1];
        }

        return abs(arraySummation - normalSummation);
    }
};