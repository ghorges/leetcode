// 软删除速度能快点
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int boo = nums[0];
        int num = 1;
        int allNum = nums.size();
        for (int i = 1; i < allNum; i++) {
            if (boo == nums[i]) {
                nums[i] = -12345;
                continue;
            }
            boo = nums[i];
            num++;
        }
        int index = 0;
        for (int i = 0; i < allNum; i++) {
            if (nums[i] != -12345) {
                nums[index++] = nums[i];
            }
        }
        return num;
    }
};
