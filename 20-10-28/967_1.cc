// 这种其实就是把递归写成非递归的形式而已
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> arr(0);
        if (n == 0 && k == 0) {
            arr.push_back(0);
            return arr;
        }

        set<int> data;
        for (int i=1; i<=9; i++) {
            data.insert(i);
        }
        for (int i=1; i<n; i++) {
            set<int> data1;
            for (auto &t : data) {
                int p = t%10;
                if (p-k>=0) {
                    data1.insert(t*10+p-k);
                }
                if (p+k<=9) {
                    data1.insert(t*10+p+k);
                }
            }
            data=data1;
        }
        for (auto &t : data) {
            arr.push_back(t);
        }
        return arr;
    }
};
