// 螃蟹走法，思路很新奇，看题解写的
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) {
            return false;
        }
        int m = matrix[0].size();
        if (m == 0) {
             return false;
        }

        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};
