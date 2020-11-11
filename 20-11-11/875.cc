// 需要注意k不能为0
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long sum = 0;
        for (auto &t : piles) {
            sum += t;
        }
        int k = sum / H;
        if (k == 0) {
            k = 1;
        }
        while (1) {
            int time = 0;
            for (auto &t : piles) {
                if (time > H) {
                    break;
                }
                if (t % k == 0) {
                    time += t / k;
                } else {
                    time += t / k + 1;
                }
            }
            if (time > H) {
                k++;
            } else {
                return k;
            }
        }
        return 0;
    }
};
