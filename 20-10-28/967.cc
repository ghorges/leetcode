// 递归方式 本质上就是将这些数都遍历出来
void dfs(int data, int k, int min, int max, vector<int> &arr);
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> arr(0);
        if (n == 0 && k == 0) {
            arr.push_back(0);
            return arr;
        }

        int min = 1, max = 9;
        for (int i = 1; i < n; i++) {
            min *= 10;
            max = max * 10 + 9; 
        }
        for (int i = 1; i <= 9; i++) {
            dfs(i, k, min, max, arr);
        }
        return arr;
    }
};

void dfs(int data, int k, int min, int max, vector<int> &arr) {
    if (data >= min && data <= max) {
        arr.push_back(data);
        return;
    }
    if (data > max) {
        return;
    }
    int t = data % 10; 
    if (t - k >= 0) {
        dfs(data*10+t-k, k, min, max, arr);
    }
    if (t + k <= 9) {
        if (k != 0)
        dfs(data*10+t+k, k, min, max, arr);
    }
    return;
}
