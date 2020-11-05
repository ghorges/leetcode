class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> data;
        for (int i = 0; i < nums.size(); i++) {
            data[nums[i]].push_back(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            auto m = data.find(target - nums[i]);
            if (m == data.end()) {
                continue;
            }
            for (auto &t : m->second) {
                if (t != i) {
                    return vector<int>{i, t};
                }
            }
        } 
        return vector<int>{};
    }
};
