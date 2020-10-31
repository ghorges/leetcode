// 本来以为二进制的位数有什么更简单的方法的，结果没有
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
        set <int> boo;
        for (auto t : arr) {
            boo.insert(t);
        }
        int sum = 0;
        for (int i = L; i <= R; i++) {
            int num = 0;
            int far = i;
            while (far) {
            if (far % 2 == 1) {
                num++;
            }
            far /= 2;
            }
            if (boo.find(num) != boo.end()) {
                sum++;
            }
        }
        return sum;
    }
};
