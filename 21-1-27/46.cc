// 面试被问到全排列，没答上来，刷一下
// 本质上就是通过递归+交换实现的
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rec(0);
        getall(rec, nums, 0, nums.size());
        return rec;
    }
    void getall(vector<vector<int>>& rec, vector<int>& nums, int l, int len) {
        if (l >= len)
        {
            rec.push_back(nums);
            return;
        }

        for (int i = l; i < len; i++)
        {
            swap(nums[l], nums[i]);
            getall(rec, nums, l + 1, len);
            // 再换回来
            swap(nums[l], nums[i]);
        }
    }
};
