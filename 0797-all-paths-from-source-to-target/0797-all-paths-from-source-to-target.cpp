class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int target = graph.size() - 1;
        vector<vector<int>> paths, targets;

        // Initialize paths with the source node (0)
        paths.push_back({0});

        while (!paths.empty())
        {
            vector<int> path = paths.front();
            paths.erase(paths.begin());

            vector<int> edges = graph[path.back()];
            if (edges.empty())
            {
                continue;
            }

            for (int edge : edges)
            {
                if (edge == target)
                {
                    targets.push_back(path);
                    targets.back().push_back(edge);
                }
                else
                {
                    paths.push_back(path);
                    paths.back().push_back(edge);
                }
            }
        }

        return targets;
    }
};