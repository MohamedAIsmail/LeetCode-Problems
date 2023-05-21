class Solution
{
    vector<pair<int, int>> first, second;
    int ans = 30000, islandCtr = 1;

public:
    void DFS(int i, int j, stack<pair<int, int>> st, vector<vector<int>> &grid, vector<pair<int, int>> &vec)
    {
        st.push({i, j});
        grid[i][j] = 4;

        while (!st.empty())
        {
            pair<int, int> temp = st.top();
            vec.push_back(temp);
            st.pop();
            int row = temp.first, col = temp.second;

            if (row > 0 && grid[row - 1][col] == 1)
            {
                grid[row - 1][col] = 4;
                st.push({row - 1, col});
            }
            if (col > 0 && grid[row][col - 1] == 1)
            {
                grid[row][col - 1] = 4;
                st.push({row, col - 1});
            }

            if (row + 1 < grid.size() && grid[row + 1][col] == 1)
            {
                grid[row + 1][col] = 4;
                st.push({row + 1, col});
            }

            if (col + 1 < grid[0].size() && grid[row][col + 1] == 1)
            {
                grid[row][col + 1] = 4;
                st.push({row, col + 1});
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                stack<pair<int, int>> st;
                if (grid[i][j] == 1)
                {
                    if (islandCtr == 1)
                    {
                        DFS(i, j, st, grid, first);
                    }
                    else
                    {
                        DFS(i, j, st, grid, second);
                    }
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