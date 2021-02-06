// 滑动窗口解决，就是运行速度慢
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> rec(0);
        if (target == 0) {
            return rec;
        }
        if (target == 1) {
            vector<int> ins;
            ins.push_back(1);
            rec.push_back(ins);
            return rec;
        }
        int i = 1;
        list<int> t;
        while(1) {
            if (i > target / 2 + 3) {
                break;
            }
            int sum = 0;
            for (auto &q : t) {
                sum += q;
            }
            if (sum > target) {
                t.pop_front();
            }
            if (sum < target) {
                t.push_back(i);
                i++;
            }
            if (sum == target) {
                vector<int> nums;
                for (auto &q : t) {
                    nums.push_back(q);
                }
                rec.push_back(nums);
                t.pop_front();
            }
        }
        return rec;
    }
};
