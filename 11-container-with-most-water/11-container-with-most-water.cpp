class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int maxA = 0;
        while (i != j)
        {
            int w = j - i;
            int h = min(height[i], height[j]);

            if ((w * h) > maxA)
            {
                maxA = w * h;
            }

            if (height[i] >= height[j])
                j--;
            else
                i++;
        }
        return maxA;
    }
};