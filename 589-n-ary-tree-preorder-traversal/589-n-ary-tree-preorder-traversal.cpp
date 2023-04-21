/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {

        vector<int> result;

        if (!root)
            return result;

        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();

            vector<Node *> v = temp->children;
            result.push_back(temp->val);

            for (int i = v.size() - 1; i >= 0; i--)
                st.push(v[i]);
        }

        return result;
    }
};