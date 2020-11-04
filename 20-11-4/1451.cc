// stable_sort 是稳定排序，不能用sort
class Solution {
public:
    string arrangeWords(string text) {
        if (text.size() <= 1) {
            return text;
        }
        text[0] -= ('A' - 'a');
        vector<string> strs;
        strs = split(text);
        stable_sort(strs.begin(), strs.end(), cmp);
        return resplit(strs);
    }
    static bool cmp(string str1, string str2) {
        return str1.size() < str2.size();
    }
    vector<string> split(string text) {
        int t = 0;
        vector<string> strs;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                string str;
                str.append(text, t, i - t);
                strs.push_back(str);
                t = i + 1;
            }
        }
        string str;
        str.append(text, t, text.size() - t);
        strs.push_back(str);
        return strs;
    }
    string resplit(vector<string> strs) {
        string str = "";
        for (int i = 0; i < strs.size(); i++) {
            str += strs[i];
            if (i == strs.size() - 1) {
                continue;
            }
            str += ' ';
        }
        str[0] += ('A' - 'a');
        return str;
    }
};
