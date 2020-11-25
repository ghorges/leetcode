class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
       int n = nums.size();
        if (nums.length() == 0 || nums[0] == '0') {
            return 0;
        }
        vector<int> data(n + 1, 0);
        data[0] = 1;
        for (int i = 1; i <= n; i++) {
            int t = 0;
            if (nums[i - 1] != '0') {
                t += data[i - 1];
            }
            if (i > 1) {
                if (nums[i - 2] == '1' || ((nums[i - 2] == '2' && nums[i - 1] <= '6'))) {
                    t += data[i - 2];
                }
            }
            data[i] = t;
        }
        return data.back();
    }
};
