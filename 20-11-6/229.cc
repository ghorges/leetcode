// 自己想到了 map 方法，但是空间复杂度高
// 看了题解的摩尔投票法的思想写的
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        int a1, a2;
        int count1 = 0;
        int count2 = 0;
        bool flag = true;
        for (auto &t : nums) {
            if (a1 == t) {
                count1++;
                continue;
            }
            if (a2 == t) {
                count2++;
                continue;
            }
            if (count1 == 0) {
                a1 = t;
                count1++;
                continue;
            }
            if (count2 == 0) {
                a2 = t;
                count2++;
                continue;
            }
            count1--;
            count2--;
        }
        int num1 = 0, num2 = 0;
        for (auto &t : nums) { 
            if (t == a1)
                num1++;
            if (t == a2)
                num2++;
        }
        vector<int> data;
        if (num1 > nums.size()/3)
            data.push_back(a1);
        if (num2 > nums.size()/3)
            data.push_back(a2);        
        return data;
    }
};
