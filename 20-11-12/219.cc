class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> boo;
        for (int i = 0; i < nums.size(); i++) {
            boo[nums[i]].push_back(i);
        }
        for (auto &vec : boo) {
            auto arr = vec.second;
            if (arr.size() <= 1) {
                continue;
            }
            sort(arr.begin(), arr.end());
            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] - arr[i - 1] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};
