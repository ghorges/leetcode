// 不仅仅得用模拟，还得用位运算，否则会超时
class Solution {
public:
    int kong = 0;
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0) return cells;
        int index = -1;
        int size = cells.size();
        map<int, int> nightData;    // 将值转换成 int 进行存储
        int bin = changeToInt(cells);
        nightData[bin] = ++index;
        while (1) {
            int t = ~(bin << 1 ^ bin >> 1) & 0x7E;
            auto mdata = nightData.find(t);
            if (mdata != nightData.end()) {
                kong = index - mdata->second + 1;
                break;
            }
            nightData[t] = ++index;
            bin = t;
        }
        
        while (N > index) {
            N -= kong;
        }
        // return changeToArr(kong);
        for (auto &m : nightData) {
            if (m.second == N) {
                return changeToArr(m.first);
            }
        }
        return vector<int>(8);
    }
    int changeToInt(vector<int>& arr) {
        int n = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            n  = n*2 + arr[i];
        }
        return n;
    }
    vector<int> changeToArr(int n) {
        vector<int> arr(8);
        int i = 0;
        while (n) {
            if (n % 2) {
                arr[i++] = 1;
            } else {
                arr[i++] = 0;
            }
            n /= 2;
        }
        // reverse 还挺好用
        return arr;
    }
};
