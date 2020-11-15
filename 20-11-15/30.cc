// 没想到是个困难，就是写的比较慢
// 思想很简单，放入 map 就行
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0) {
            return vector<int>(0);
        }
        map<string, int> boo;
        for (auto &t : words) {
            boo[t]++;
        }
        map<string, int> booSwap(boo);
        // 记录这个 words 的长度
        int count = words.size();
        int wlen = words[0].length();
        int len = s.size() - wlen * count;
        vector<int> data(0);
        for (int i = 0; i <= len; i++) {
            int j = i;
            while(1) {
            string str = "";
            int k = j;
            for (; k < j + wlen && k < s.size(); k++) {
                str += s[k];
            }
            if (str.length() != wlen) {
                break;
            }
            // data.push_back(str.length());
            auto far = boo.find(str);
            if (far == boo.end()) {
                break;
            }
            if (far->second <= 0) {
                break;
            }
            far->second--;
            count--;
            j += wlen;
        }
        if (count == 0) {
            data.push_back(i);
        }
        // data.push_back(count);
        boo = booSwap;
        count = words.size();
        }
        return data;
    }
};
