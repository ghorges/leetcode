// 这是个找规律题 找到规律就做出来了
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        if (n == 4) {
            return 4;
        }
        int sum = 3;
        n -= 3;
        while(1)
        {
            if (n == 4) {
                sum *= n;
                break;
            }
            if (n > 3) {
                sum *= 3;
                n -= 3;
                continue;
            }
            sum *= n;
            break;
         }
         return sum;
    }
};
