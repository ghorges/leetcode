class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *p = &A[m - 1], *q = &B[n - 1], *t = &A[m + n - 1];
        
        while(m + n > 0) {
            if (m > 0 && n > 0) {
                if (*p > *q) {
                    *t = *p;
                    m--;
                    p--;
                    t--;
                } else {
                    *t = *q;
                    n--;
                    q--;
                    t--;
                }
            } else {
                while(m > 0) {*t = *p; m--; p--;t--;}
                while(n > 0) {*t = *q; n--; q--;t--;}
            }
        }
    }
};
