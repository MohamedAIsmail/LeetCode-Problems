class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int row = 0, col = 0;
        int sum = 0;

        while (row < mat[0].size() && col < mat.size())
        {
            sum += mat[row][col];
            row++;
            col++;
        }

        col = mat.size() - 1;
        row = 0;
        while (row < mat[0].size() && col >= 0)
        {
            sum += mat[row][col];
            row++;
            col--;
        }

        if (mat.size() % 2 != 0)
        {
            int n = mat.size() / 2;
            return (sum - mat[n][n]);
        }
        else
        {
            return sum;
        }
    }
};