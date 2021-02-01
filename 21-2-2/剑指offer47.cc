// 用 dfs 会超时，得用动归，仔细看题可以发现
// 因为只能向下和向右走，所以构造一个二维数组就可以了
class Solution {
public:
    int m, n;
    int Max = 0;
    int maxValue(vector<vector<int>>& grid) {
        m = grid.size();
        cout << m << endl;
        if (m == 0) 
            return 0;
        n = grid[0].size();
        cout << n << endl;
        if (n == 0)
            return 0;
        // dfs(grid, 0, 0, 0);
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }

    // dfs 超时了
    void dfs(vector<vector<int>>& grid, int i, int j, int sum) {
        if (i == m - 1 && j == n - 1) {
            Max = max(Max, sum);
            return;
        }
        if (i + 1 < m)
            dfs(grid, i + 1, j, sum + grid[i][j]);
        if (j + 1 < n)
            dfs(grid, i, j + 1, sum + grid[i][j]);
    }
};
