/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int maxWidth = 0;

        if (root == nullptr)
            return maxWidth;

        queue<pair<TreeNode *, int>> queue;

        queue.push({root, 0});

        while (!queue.empty())
        {
            int count = queue.size();
            int start = queue.front().second;
            int end = queue.back().second;
            maxWidth = max(maxWidth, end - start + 1);

            for (int i = 0; i < count; i++)
            {
                pair<TreeNode *, int> p = queue.front();
                int idx = p.second;
                queue.pop();
                if (p.first->left)
                    queue.push({p.first->left, idx * 2LL + 1});
                if (p.first->right)
                {
                    queue.push({p.first->right, idx * 2LL + 2});
                }
            }
        }

        return maxWidth;
    }
};
