class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> q1, q2;
        int n = senate.size();

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
                q1.push(i);
            else
                q2.push(i);
        }

        while (!q1.empty() && !q2.empty())
        {
            int r = q1.front();
            int d = q2.front();
            q1.pop();
            q2.pop();

            if (r < d)
                q1.push(n + r);
            else
                q2.push(n + d);
        }

        if (!q1.empty())
            return "Radiant";
        else
            return "Dire";
    }
};