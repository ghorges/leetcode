// 两个指针，然后对两边中间的进行动归（不是对全部剩下的进行动归，对全部剩下的动归超时）
// 题解有的是错的，因为删除的是左边或者右边都可能有问题，我想到通过动归解决了
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = -1, r = -1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i+1]) {
                l = i;
                break;
            }
        }
        for (int i = arr.size() - 1; i > 0; i--) {
            if (arr[i] < arr[i-1]) {
                r = i;
                break;
            }
        }
        if (l == -1 || r == -1) {
            return 0;
        }
        /*
        vector<int> arrList;
        for (int i = 0; i <= l; i++) {
            arrList.push_back(arr[i]);
        }
        for (int i = r; i < arr.size(); i++) {
            arrList.push_back(arr[i]);
        }
        return arr.size() - findList(arrList);
        */
        vector<int> arrList;
        for (int i = 0; i <= l; i++) {
            if (arr[r] < arr[i])
                arrList.push_back(arr[i]);
        }
        for (int i = r; i < arr.size(); i++) {
            if (arr[l] > arr[i])
            arrList.push_back(arr[i]);
        }
        return arrList.size() - findList(arrList) + r - l - 1;
    }
    // 最后剩下的前面和后面，用动归超时了，怎么解决？
    // 只对中间的动归试试
    int findList(vector<int>& arr) {
        if (arr.size() <= 1) {
            return arr.size();
        }
        vector<int> data(arr.size());
        data[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            int n = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i] >= arr[j]) {
                    n = max(data[j] + 1, n);
                }
            }
            data[i] = n;
        }

        int m = 0;
        for (int i = 0; i < arr.size(); i++) {
            m = max(data[i], m);
        }
        return m;
    }
};
/*
// 子数组必须是连续的，我写的这个删除的是可以不连续的，动归
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() == 0 || arr.size() == 1) {
            return 0;
        }

        vector<int> data(arr.size());
        data[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            int n = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i] >= arr[j]) {
                    n = max(data[j] + 1, n);
                }
            }
            data[i] = n;
        }

        int m = 0;
        for (int i = 0; i < arr.size(); i++) {
            m = max(data[i], m);
        }
        return arr.size() - m;
    }
};
*/
