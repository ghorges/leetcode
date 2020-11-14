// 每次只反转最大的，最多需要两次
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> boo(0);
        for (int i = 0; i < arr.size(); i++) {
            int mIndex = 0;
            int maxi = arr.size() - 1 - i;
            for (int j = arr.size() - 1 - i; j > 0; j--) {
                if (arr[mIndex] < arr[j]) {
                    mIndex = j;
                }
            }
            if (mIndex == 0) {
                boo.push_back(maxi + 1);
                vecReverse(arr, 0, maxi);
                continue;
            }
            if (mIndex == maxi) {
                continue;
            }
            boo.push_back(mIndex + 1);
            vecReverse(arr, 0, mIndex);
            boo.push_back(maxi + 1);
            vecReverse(arr, 0, maxi);
        }
        return boo;
    }
    void vecReverse(vector<int>& boo, int l, int r) {
        while(l < r) {
            swap(boo[l], boo[r]);
            l++;r--;
        }
    }
};

