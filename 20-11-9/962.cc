// 单调栈解决问题
// 还是有点糊，没事再想想
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        if (A.size() <= 1) {
            return 0;
        }
        stack<int> s;
        s.push(0);
        for (int i = 1; i < A.size(); i++) {
            if (A[s.top()] > A[i]) {
                s.push(i);
            }
        }

        int res = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            while(!s.empty() && A[i] >= A[s.top()]) {
                res = max(res, i - s.top());
                s.pop();
            }
        }
        return res;
    }
};
