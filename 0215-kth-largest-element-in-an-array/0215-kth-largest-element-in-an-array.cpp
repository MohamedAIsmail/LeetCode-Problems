class Solution {
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> dataSet;

        for (int i = 0; i < nums.size(); i++)
        {
            dataSet.push(nums[i]);
            if(dataSet.size() > k)
                dataSet.pop();
        }

        return dataSet.top();
    }
};