class Solution
{
    int ans = INT_MAX, islandCtr = 2;
    vector<pair<int, int>> first, second;

public:
    void DFS(int i, int j, int no, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return;

        grid[i][j] = no;

        if (no == 2)
            first.push_back({i, j});
        else
            second.push_back({i, j});

        DFS(i + 1, j, no, grid);
        DFS(i - 1, j, no, grid);
        DFS(i, j + 1, no, grid);
        DFS(i, j - 1, no, grid);
    }

    int shortestBridge(vector<vector<int>> &grid)
    {

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    DFS(i, j, islandCtr, grid);
                    islandCtr++;
                }
            }
        }

        for (int i = 0; i < first.size(); i++)
        {
            for (int j = 0; j < second.size(); j++)
            {
                ans = min(ans, abs(first[i].first - second[j].first) + abs(first[i].second - second[j].second) - 1);
            }
        }
        return ans;
    }
};