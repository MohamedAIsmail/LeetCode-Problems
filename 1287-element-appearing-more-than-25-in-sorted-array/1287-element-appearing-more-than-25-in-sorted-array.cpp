class Solution {
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int bucketSize = n * 0.25;

        for (int i = 0; i < n - bucketSize; i++)
        {
            if (arr[i] == arr[i + bucketSize])
            {
                return arr[i];
            }
        }

        return -1;
    }
};