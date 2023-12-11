class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if(n == 0) return 0;

        vector<int> stock(n + 1);
        vector<int> profit(n + 1);

        stock[1] = -prices[0];
        profit[1] = 0;

        for (int i = 1; i < n; i++){
            stock[i + 1] = max(stock[i], profit[i - 1] - prices[i]);
            profit[i + 1] = max(profit[i], stock[i] + prices[i]);
        }

        return profit[n];
    }
};