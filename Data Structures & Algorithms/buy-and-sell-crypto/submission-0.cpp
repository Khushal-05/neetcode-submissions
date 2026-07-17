class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> bestBuy(n);
        bestBuy[0] = prices[0];

        for(int i=1; i<n; i++){
            bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
        }
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            int profit = prices[i] - bestBuy[i];
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};
