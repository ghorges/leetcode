// dfs应该没问题，但是超时了，以后先不刷图的,弗洛伊德真不会
class Solution {
public:
    struct nodeData {
        int node;
        int num;
    };
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        map <int, vector<nodeData>> data;
        set <int> citys;
        for (auto &arr : edges) {
            nodeData boo;
            boo.node = arr[1];
            boo.num = arr[2];
            data[arr[0]].push_back(boo);

            boo.node = arr[0];
            data[arr[1]].push_back(boo);
            citys.insert(arr[0]);
            citys.insert(arr[1]);
        }
        int sum = 0;
        int index = 0;
        bool flag = true;
        for (auto &boo : data) {
            set <int> far;
            set <int> city;
            far.insert(boo.first);
            city.insert(boo.first);
            dfs(data, boo.first, distanceThreshold, far, city);
            if (flag) {
                flag = false;
                sum = city.size();
                index = boo.first;
                continue;
            }
            if (sum > city.size()) {
                sum = city.size();
                index = boo.first;
            }
            if (sum == city.size()) {
                if (index < boo.first) {
                    sum = city.size();
                    index = boo.first;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (citys.find(i) == citys.end()) {
                if (sum != 0) {
                    index = i;
                    sum = 0;
                }
                if (sum == 0 && index < i) {
                    index = i;
                }
            }
        }
        return index;
    }

    void dfs(map<int, vector<nodeData>>&data, int i, int len, set<int>& far, set<int>& city) {
        if (len <= 0) {
            return;
        }
        int num = 0;
        for (auto &boo : data[i]) {
            if (far.find(boo.node) == far.end()) {
                if (boo.num <= len) {
                    city.insert(boo.node);
                    far.insert(boo.node);
                    dfs(data, boo.node, len - boo.num, far, city);
                    far.erase(boo.node);
                }
            }
        }
        return;
    }
};
