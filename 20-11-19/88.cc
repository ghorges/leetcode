class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> data(0);
        while(i < m || j < n) {
            if (i == m) {
                data.push_back(nums2[j]);
                j++;
                continue;
            }
            if (j == n) {
                data.push_back(nums1[i]);
                i++;
                continue;
            }
            if (nums1[i] < nums2[j]) {
                data.push_back(nums1[i]);
                i++;
            } else {
                data.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = data;
    }
};
