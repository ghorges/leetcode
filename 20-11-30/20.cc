class Solution {
public:
    bool isValid(string s) {
        stack<char> data;
        for (auto &t : s) {
            if (data.empty()) {
                data.push(t);
                continue;
            }
            char c = data.top();
            if (c == '[' && t == ']') {
                data.pop();
                continue;
            }
            if (c == '(' && t == ')') {
                data.pop();
                continue;
            }
            if (c == '{' && t == '}') {
                data.pop();
                continue;
            }
            data.push(t);
        }
        if (data.empty()) {
            return true;
        }
        return false;
    }
};
