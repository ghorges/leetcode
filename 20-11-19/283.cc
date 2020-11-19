class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> zero;
        for (auto &t : nums) {
            if (t)
            zero.push_back(t);
        }
        while(nums.size() != zero.size()) {
            zero.push_back(0);
        }
        nums = zero;
    }
};
