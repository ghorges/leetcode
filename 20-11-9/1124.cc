// 借用了一下上一个的代码
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> time;
        int ans = 0;
        for (auto &t : hours) {
            int m = t > 8 ? 1 : -1;
            ans+=m;
            time.push_back(ans);
        }
        int t = maxWidthRamp(time);
        return t;
    }

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
            if(A[i] > 0) {
                res = max(res, i + 1);
                break;
            }
            while(!s.empty() && A[i] > A[s.top()]) {
                res = max(res, i - s.top());
                s.pop();
            }
        }
        return res;
    }
};
