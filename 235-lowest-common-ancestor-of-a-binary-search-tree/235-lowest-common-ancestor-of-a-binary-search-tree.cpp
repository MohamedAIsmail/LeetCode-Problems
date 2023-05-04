/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> vec1, vec2;
        int ctr = -1;
        
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *temp = root;
        vec1.push_back(temp);
        while (temp != p)
        {
            if (p->val < temp->val)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            vec1.push_back(temp);
        }

        temp = root;
        vec2.push_back(temp);
        while (temp != q)
        {
            if (q->val < temp->val)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            vec2.push_back(temp);
        }

        int n = min(vec1.size(), vec2.size());
        for (int i = 0; i < n; i++)
        {
            if (vec1[i] == vec2[i])
                ctr++;
        }

        return vec1[ctr];
    }
};