// 大一软协面试的题了，有点怀念啊！
class Solution {
public:
    map<int, int> t;
    int climbStairs(int n) {
        t[1] = 1;
        t[2] = 2;
        return dfs(n);
    }
    int dfs(int n) {
        if (n <= 0) {
            return 0;
        }
        if (t.find(n) != t.end()) {
            return t[n];
        }
        int m = climbStairs(n - 1) + climbStairs(n - 2);
        t[n] = m;
        return m;
    }
};
