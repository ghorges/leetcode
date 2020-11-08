// 遍历就可以了
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        if (A.size() == 1) {
            return 1;
        }
        int n = 0;
        bool flag = false;
        int swap = 0;
        for (int i = 0; i < A.size() - 1; i++) {
            if(i % 2) {
                if(A[i] > A[i+1]) {
                    if(flag == false) {
                        flag = true;
                        swap = 1;
                    } else {
                        swap++;
                    }
                } else {
                    flag = false;
                }
            } else {
                if(A[i] < A[i+1]) {
                    if(flag == false) {
                        flag = true;
                        swap = 1;
                    } else {
                        swap++;
                    }
                } else {
                    flag = false;
                }
            }
            n = max(n, swap);
        }
        flag = false;
        swap = 0;
        for (int i = 0; i < A.size() - 1; i++) {
            if(i % 2) {
                if(A[i] < A[i+1]) {
                    if(flag == false) {
                        flag = true;
                        swap = 1;
                    } else {
                        swap++;
                    }
                } else {
                    flag = false;
                }
            } else {
                if(A[i] > A[i+1]) {
                    if(flag == false) {
                        flag = true;
                        swap = 1;
                    } else {
                        swap++;
                    }
                } else {
                    flag = false;
                }
            }
            n = max(n, swap);
        }
        return n + 1;
    }
};
