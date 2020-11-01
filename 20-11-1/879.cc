// 目只会用递归做，但是超时

class Solution {
public:
    unsigned long long allSum = 0;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<int> profitList(0);
        dfs(G, P, 0, group, profit, profitList);
        unsigned long long mod = pow(10, 9) + 7;
        return int(allSum % mod);
    }

    void dfs(int G, int P, int index, vector<int>& group, vector<int>& profit, vector<int>& profitList) {
        if (G >= 0 && P <= 0) {
            allSum++;
        } 
        if (G < 0 || (G == 0 && P > 0)) {
            return;
        }
        for (int i = index; i < profit.size(); i++) {
            profitList.push_back(i);
            dfs(G - group[i], P - profit[i], i + 1, group, profit, profitList);
            profitList.pop_back();
        }
    }
};
