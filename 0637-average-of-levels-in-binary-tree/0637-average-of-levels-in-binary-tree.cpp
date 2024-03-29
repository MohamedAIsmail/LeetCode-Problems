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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode* > q;
        int nodesLevel = 0, ctr = 0;
        q.push(root);
        vector<double> result;

        while(!q.empty()){
            int n = q.size();
            double avg = 0.0;
            for (int i = 0; i < n; i++){
                TreeNode *curr = q.front();
                avg += curr->val;
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            result.push_back(avg / double(n));
        }

        return result;
    }
};