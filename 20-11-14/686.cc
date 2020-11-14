// 最后的a不能太长，得判断终止基
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a.empty()) {
            return -1;
        }
        int count = 1;
        string boo = a;
        int i = 0;
        while (a.length() < b.length()) {
            a += boo;
            count++;
        }
        if (a.find(b) != a.npos) {
            return count;
        }
        a += boo;
        count++;
        if (a.find(b) != a.npos) {
            return count;
        }
        return -1;
    }
};
