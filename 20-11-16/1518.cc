// 很简单，两个 int 就可
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = numBottles;
        int t = 0;
        int sum = 0;
        while(1) {
            sum += n;
            t += n;
            n = 0;
            if (t < numExchange) {
                break;
            }
            n = t / numExchange;
            t %= numExchange; 
        }
        return sum;
    }
};
