// 应该写一个函数的，要不很乱
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if (nums.size() <= 1) {
            return vector<int>(0);
        }
        int n = 0;
        for(auto &t : nums)
        {
            n = n ^ t;
        }
        if (n == 0)
        {
            return vector<int>(0);
        }

        cout << (n & 1) << endl;
        int i = 1;
        while(1) {
            if ((n | i) == n) {
                break;
            }
            i *= 2;
        }
        vector<int> num1;
        vector<int> num2;
        for (auto &t : nums)
        {
            if ((t | i) == t) {
                num1.push_back(t);
            } else {
                num2.push_back(t);
            }
        }

        vector<int> rec(0); 
        n = 0;
        for(auto &t : num1)
        {
            n = n ^ t;
        }
        rec.push_back(n);
                n = 0;
        for(auto &t : num2)
        {
            n = n ^ t;
        }
        rec.push_back(n);
        return rec;
    }
};
