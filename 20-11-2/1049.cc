// 自己想的想法太简单了，还是得用0-1背包
// 处处0-1背包，万事先想0-1背包。。。
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return stones[0];
        }

        int sum = 0;
        for (auto &t : stones) {
            sum += t;
        }

        int dp[n][sum + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][stones[0]] = 1;
        for (int i = 1; i < n; i++) {
            int boo = stones[i];
            dp[i][boo] = 1;
            for (int j = 0; j <= sum; j++) {
                if (dp[i - 1][j] != 0) {
                    dp[i][j] = 1;
                    int k2 = j + boo;
                    dp[i][k2] = 1;
                }
            }
        }

        int t = sum / 2;
        int index = 0;
        for (int i = 0; i <= sum; i++) {
            if (dp[n - 1][i] == 1) {
                if (abs(i - t) <= abs(index - t)) {
                    index = i;
                }              
            }
        }
        return abs(sum - 2*index);
    }
};
