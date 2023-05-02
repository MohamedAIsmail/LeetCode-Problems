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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> result;
        vector<int> level;

        if (root == nullptr)
        {
            return result;
        }

        que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            level.clear();
            while (size--)
            {
                
                TreeNode *temp = que.front();
                level.push_back(que.front()->val);
                que.pop();
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }

            if (!level.empty())
            {
                result.push_back(level);
            }
        }
        return result;
    }
};