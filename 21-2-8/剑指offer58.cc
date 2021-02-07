// 1 + 1 = 2 
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.length();
        if (n > len) {
            return s;
        }

        string s1(s, n);
        for (int i = 0; i < n; i++) {
            s1 += s[i];
        }
        return s1;
    }
};
