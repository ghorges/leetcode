// 本质上就是排序，我的思路麻烦，应该用题解的
// 若 x+y > y+x 而不是我把 x*y 次和 y*x 次
class Solution {
public:
    static bool match(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        string strCopy1 = str1;
        string strCopy2 = str2;
        while (len1--)
        {
            str2 += strCopy2;
        }
        while(len2--) {
            str1 += strCopy1;
        }
        return str1 < str2;
    }
    string minNumber(vector<int>& nums) {
        vector<string> strNums;
        for(auto &t : nums) {
            strNums.push_back(to_string(t));
        }
        std::sort(strNums.begin(), strNums.end(), match);
        string rec;
        for (auto &str : strNums) {
            rec += str;
        }
        return rec;
    }
};
