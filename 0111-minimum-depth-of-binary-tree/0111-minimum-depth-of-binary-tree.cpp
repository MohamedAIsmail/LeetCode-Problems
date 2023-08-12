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
class Solution {
public:
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> Q;

        if(!root)
            return 0;

        Q.push(root);
        int no_Nodes = 1;

        while(!Q.empty()){
            int n = Q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = Q.front();
                Q.pop();
                if (!curr->left && !curr->right)
                {
                    return no_Nodes;
                }
                if (curr->left)
                    Q.push(curr->left);
                if (curr->right)
                    Q.push(curr->right);
            }
            no_Nodes++;
        }

        return no_Nodes;
    }
};