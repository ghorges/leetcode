// 没想到双指针法，双指针法确实速度快
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                return vector<int>{nums[i], nums[j]};
            }
            if (sum < target)
            {
                i++;
            }
            if (sum > target)
            {
                j--;
            }
        }
        return vector<int>(2);
    }
    vector<int> twoSum1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (target - nums[i] < nums[i + 1])
            {
                return vector<int>(2);
            }
            int j = findSortNum(nums, target - nums[i], i + 1, nums.size() - 1);
            if (j == -1 || j == i)
            {
                continue;
            }
            return vector<int>{nums[i], nums[j]};
        }

        return vector<int>(2);
    }

    int findSortNum(vector<int>& nums, int target, int l, int r) {
        while (l <= r)
        {
            int mid = (l + r) / 2;
            cout << mid << endl;
            if (nums[mid] == target)
            {
                if (mid + 1 <= nums.size() - 1 && nums[mid + 1] == target)
                {
                    return mid + 1;
                } else {
                    return mid;
                }
            }
            if (nums[mid] < target)
            {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
