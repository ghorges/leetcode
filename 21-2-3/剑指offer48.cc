// map 解决
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        map<char, int> str;
        str[s[0]] = 0;
        int maxLen = 0;
        int pre = 0;
        for (int i = 1; i < s.length(); i++) {
            if (str.find(s[i]) != str.end()) {
                if (str[s[i]] + 1 > pre)
                pre = str[s[i]] + 1;
            }
            maxLen = maxLen > (i - pre + 1) ? maxLen : (i - pre + 1);
            cout << i << "  " << pre << endl;
            str[s[i]] = i;
        }
        return maxLen;
    }
};
