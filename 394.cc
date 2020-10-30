// 遍历并将之前的值弄出来，看题解的
class Solution {
public:
    string decodeString(string s) {
        if (s == "") {
            return "";
        }
        int i = 0;
        return dfs(s, 0, i);
    }
    string dfs(string s, int l, int &r) {
        int n = 0;
        string allStr;
        for (int i = l; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + s[i] - '0';
                continue;
            }
            if (s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z') {
                allStr += s[i];
                continue;
            }
            if (s[i] == '[') {
                string t = dfs(s, i + 1, r);
                for (int j = 0; j < n; j++) {
                    allStr += t;
                }
                i = r;
                n = 0; 
                continue;
            }
            if (s[i] == ']') {
                r = i;
                return allStr;
            }      
        }
        r = s.size() - 1;
        return allStr;
    }
};
