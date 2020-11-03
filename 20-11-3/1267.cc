// 两个 map 完事
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int M = grid.size();
        int N = grid[0].size();

        map <int, int> mMap;
        map <int, int> nMap;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    mMap[i]++;
                    nMap[j]++;
                }
            }
        }

        int sum = 0;
        int count = 0;
            for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    count++;
                    if (mMap[i] == 1 && nMap[j] == 1) {
                        sum++;
                    }
                }
            }
        }
        return count - sum;
    }
};
