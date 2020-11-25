class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    struct node{
        int key;
        int value;
        bool operator==(node boo) {
            if (this->key == boo.key)
                return true;
            return false;
        }
    };
    list<node> lists;
    map<int, int> lmap;
    unsigned long cap = 0;
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        cap = k;
        // write code here
        vector<int> rec(0);
        for (auto &t : operators) {
            if (t[0] == 1) {
                set(t[1], t[2]);
            }
            if (t[0] == 2) {
                rec.push_back(get(t[1]));
            }
        }
        return rec;
    }
    
    void set(int key, int value) {
       node boo;
       boo.value = value;
       boo.key = key;
        auto far = lmap.find(key);
        if (far != lmap.end()) {
            lists.remove(boo);
            lists.push_front(boo);
            lmap[key] = value;
            return;
        }
        if (cap == lists.size()) {
            auto t = lists.back();
            lmap.erase(t.key);
            lists.pop_back();
        }
        lists.push_front(boo);
        lmap[key] = value;
    }
    
    int get(int key) {
        auto far = lmap.find(key);
        if (far == lmap.end()) 
            return -1;
               node boo;
       boo.value = far->second;
       boo.key = key;
            lists.remove(boo);
            lists.push_front(boo);
           return far->second;
    }
};
