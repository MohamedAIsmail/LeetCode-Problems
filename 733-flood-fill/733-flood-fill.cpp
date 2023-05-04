class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialValue = image[sr][sc];
        if (color == initialValue)
        {
            return image;
        }

        queue<pair<int, int>> idxQueue;
        image[sr][sc] = color;
        idxQueue.push({sr, sc});

        while (!idxQueue.empty())
        {
            pair<int, int> curr = idxQueue.front();
            idxQueue.pop();
            if (curr.first - 1 >= 0 && image[curr.first - 1][curr.second] == initialValue)
            {
                idxQueue.push({curr.first - 1, curr.second});
                image[curr.first - 1][curr.second] = color;
            }
            if (curr.second - 1 >= 0 && image[curr.first][curr.second - 1] == initialValue)
            {
                idxQueue.push({curr.first, curr.second - 1});
                image[curr.first][curr.second - 1] = color;
            }
            if (curr.second + 1 < image[0].size() && image[curr.first][curr.second + 1] == initialValue) // image[0].size() is the number of columns
            {
                idxQueue.push({curr.first, curr.second + 1});
                image[curr.first][curr.second + 1] = color;
            }
            if (curr.first + 1 < image.size() && image[curr.first + 1][curr.second] == initialValue) // image.size() is the number of rows
            {
                idxQueue.push({curr.first + 1, curr.second});
                image[curr.first + 1][curr.second] = color;
            }
        }

        return image;
    }
};