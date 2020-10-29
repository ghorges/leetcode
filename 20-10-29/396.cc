// 看题解解的，以后也可以看看数字本身的规律
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        long maxData = 0;
        long sumData = 0;
        for (auto &t : A) {
            sumData += t;
        }
        long numAll = 0;
        for(int i = 0; i < A.size(); i++) {
            numAll += i * A[i];
        }
        maxData = numAll;
        for (int i = A.size() - 1; i >= 0; i--) {
            numAll = numAll + sumData - A.size()*A[i];
            maxData = max(maxData, numAll);
        }
        return (int)maxData;
    }
};
