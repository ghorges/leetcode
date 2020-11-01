class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pMin = 0;
        int money = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[pMin] > prices[i]) {
                pMin = i;
            }
            money = max(money, prices[i] - prices[pMin]);
        }
        return money;
    }
};
