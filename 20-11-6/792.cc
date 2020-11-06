// map 解决，for 循环注意认真写就行
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int num = 0;
        map<char, vector<int>> strMap;
        for(int i = 0; i < S.length(); i++) {
            strMap[S[i]].push_back(i);
        }
        for (auto &str : words) {
            int t = -1;
            bool flag = true;
            int i = 1;
            for(auto &ch : str) {
                auto m = strMap.find(ch);
                // 没有这个字符，跳出
                if (m == strMap.end()) {
                    flag = false;
                    break;
                }
                int flags = false;
                for (auto &n : m->second) {
                    if (n > t) {
                        t = n;
                        flags = true;
                        break;
                    }
                }
                if (flags == false) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                num++;
            }
        }
        return num;
    }
};
