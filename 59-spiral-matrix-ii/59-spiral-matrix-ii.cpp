class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int downRowBoundary = n - 1, upRowBoundary = 1, rightColBoundary = n - 1, leftColBoundary = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0, j = 0;   // i = row, j = col
        int total = n * n;
        int ctr = 1;
        while (total)
        {
            while (j <= rightColBoundary && total)
            {
                ans[i][j] = ctr;
                ctr++;
                total--;
                j++;
                
            }
            rightColBoundary--;
            j--;
            i++;

            while (i <= downRowBoundary && total)
            {
                ans[i][j] = ctr;
                ctr++;
                total--;
                i++;
            }
            downRowBoundary--;
            i--;
            j--;

            while (j >= leftColBoundary && total)
            {
                ans[i][j] = ctr;
                ctr++;
                total--;
                j--;
            }
            leftColBoundary++;
            j++;
            i--;

            while (i >= upRowBoundary && total)
            {
                ans[i][j] = ctr;
                ctr++;
                total--;
                i--;
            }
            upRowBoundary++;
            i++;
            j++;
        }

        return ans;
    }
};