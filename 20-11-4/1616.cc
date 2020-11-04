// 有好多异常注意一下就行
// 还学会这个 append
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        if(trans(a) || trans(b)) {
            return true;
        }
        int index = -1;
        for (int i = 0, j = b.size() - 1; i < a.size(); i++, j--) {
            if (a[i] == b[j]) {
                index = i;
                continue;
            } else {
                break;
            }
        }
        if (index == a.size()) {
            return true;
        }
        if (index != -1) {
            string str = "";
            str.append(a, 0, index + 1);
            str.append(b, index + 1, b.size() - index - 1);
            if (trans(str)) {
                return true;
            }
            str = "";
            str.append(a, 0, b.size() - index - 1);
            str.append(b, b.size() - index - 1, index + 1);
           if (trans(str)) {
                return true;
            }
        }

        index = -1;
        for (int i = 0, j = a.size() - 1; i < b.size(); i++, j--) {
            if (a[j] == b[i]) {
                index = i;
                continue;
            } else {
                break;
            }
        }
        if (index == b.size()) {
            return true;
        }
        if (index != -1) {
            string str = "";
            str.append(b, 0, index + 1);
            str.append(a, index + 1, a.size() - index - 1);
            if (trans(str)) {
                return true;
            }
            str = "";
            str.append(b, 0, b.size() - index - 1);
            str.append(a, b.size() - index - 1, index + 1);
           if (trans(str)) {
                return true;
            }
        }
        return false;
    }
    bool trans(string a) {
        if (a.size() <= 1) {
            return true;
        }
        int i = 0;
        int j = a.size() - 1;
        while(i < j) {
            if (a[i] != a[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
