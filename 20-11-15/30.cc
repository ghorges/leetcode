class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0) {
            return vector<int>(0);
        }
        map<string, int> boo;
        for (auto &t : words) {
            boo[t] = 1;
        }
        // 记录这个 words 的长度
        int count = words.size();
        int wlen = words[0].length();
        int len = s.size() - wlen * count;
        vector<int> data(0);
        for (int i = 0; i < len; i++) {
            int j = i;
            while(1) {
            string str = "";
            int k = j;
            for (; k < j + wlen && k < s.size(); k++) {
                str += words[k];
            }
            if (str.length() != wlen) {
                break;
            }
            auto far = boo.find(str);
            if (far == boo.end()) {
                break;
            }
            if (far->second != 1) {
                break;
            }
            far->second--;
            count--;
            j += wlen;
        }
        if (count == 0) {
            data.push_back(i);
        }
        for (auto &t : words) {
            boo[t] = 1;
        }
        count = words.size();
        }
        return data;
    }
};
