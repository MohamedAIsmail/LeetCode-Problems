class Solution
{
    // A hash function used to hash a pair of any kind
    struct hash_pair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);

            if (hash1 != hash2)
            {
                return hash1 ^ hash2;
            }

            // If hash1 == hash2, their XOR is zero.
            return hash1;
        }
    };

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islandCtr = 0;
        queue<pair<int, int>> landQue;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    landQue.push({i, j});
                    grid[i][j] = '#';

                    while (!landQue.empty())
                    {
                        pair<int, int> temp = landQue.front();
                        int row = temp.first, col = temp.second;
                        landQue.pop();

                        if (row > 0 && grid[row - 1][col] == '1')
                        {
                            grid[row - 1][col] = '#';
                            landQue.push({row - 1, col});
                        }
                        if (col > 0 && grid[row][col - 1] == '1')
                        {
                            grid[row][col - 1] = '#';
                            landQue.push({row, col - 1});
                        }

                        if (row + 1 < grid.size() && grid[row + 1][col] == '1')
                        {
                            grid[row + 1][col] = '#';
                            landQue.push({row + 1, col});
                        }

                        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1')
                        {
                            grid[row][col + 1] = '#';
                            landQue.push({row, col + 1});
                        }
                    }
                    islandCtr++;
                }
            }
        }
        return islandCtr;
    }
};