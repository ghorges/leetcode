class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL) {
            return 0;
        }
        const char *p = str;
        while(*p == ' ') p++;
        bool flag = true;
        if (*p == '-') {
           flag = false;
            p++;
        }
        if (*p == '+') {
            p++;
        }
        
        int num = 0;
        while(*p != '\0') {
            int i = *p - '0';
            if (i < 0 || i > 9) {
                return flag ? num : -num;
            }
            if (num>INT_MAX/10)
            {
                return flag?INT_MAX:INT_MIN;
            }
            num = num * 10 + i;
            p++;
        }
        return flag ? num : -num;
    }
};
