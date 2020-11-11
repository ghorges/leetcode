// 看的题解的双指针解法，确实有道理
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ret(0);
        int size1 = A.size();
        int size2 = B.size();
        int i1 = 0;
        int i2 = 0;
        while(i1 < size1 && i2 < size2) {
            int l1 = A[i1][0];
            int r1 = A[i1][1];
            int l2 = B[i2][0];
            int r2 = B[i2][1];
            if (l1 > r2) {
                i2++;
                continue;
            }
            if (l2 > r1) {
                i1++;
                continue;
            }
            vector<int> t;
            t.push_back(l1 < l2 ? l2 : l1);
            t.push_back(r1 < r2 ? r1 : r2);
            ret.push_back(t);
            if (r1 == r2) {
                i1++;
                i2++;
            }
            if (r1 < r2) {
                i1++;
            }
            if (r1 > r2) {
                i2++;
            }
        }
        return ret;
    }
};
