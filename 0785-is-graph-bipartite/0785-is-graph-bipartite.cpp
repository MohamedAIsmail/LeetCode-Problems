class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i)
        {
            if (color[i] == 0)
            {
                color[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : graph[node])
                    {
                        if (color[neighbor] == 0)
                        {
                            color[neighbor] = -color[node];
                            q.push(neighbor);
                        }
                        else if (color[neighbor] == color[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true; 
    }
};