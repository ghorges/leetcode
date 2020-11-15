// 看了题解后会了，就看因子有多少个 5 就可以了
// 因为 2 是无穷多的
class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) {
            return 0;
        }
        int count = 0;
        for (int i  = 5; i <= n; i+=5) {
            int m = 0;
            int k = i;
            while (k % 5 == 0) {
                m++;
                k /= 5;
            }
            count += m;
        }
        return count;
    }
};
