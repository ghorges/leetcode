class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0]++;
        vector<int> ret;
        int flag = 0;
        for (auto &t : digits) {
            int i = t;
            if (flag) {
                i += flag;
                flag = 0;
            }

            if (i >= 10) {
                flag += i/10;
                i %= 10;
            }
            ret.push_back(i);
        }
        if (flag) {
            ret.push_back(flag);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
