class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        for (auto &boo : s) {
            m[boo] += 1;
        }
        for (auto &boo : t) {
            m[boo] -= 1;
        }
        for (auto &boo : m) {
            if (boo.second != 0) {
                return false;
            }
        }
        return true;
    }
};
