class LRUCache {
public:
    LRUCache(int capacity) {
        m_cap = capacity;
    }
    
    int get(int key) {
        if (!hm.count(key)) return -1;
        auto it = hm[key];
        m_lists.splice(m_lists.begin(), m_lists, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (hm.count(key)) {
            auto it = hm[key];
            m_lists.erase(it);
        }
        m_lists.push_front({key, value});
        hm[key] = m_lists.begin();
        if (m_lists.size() > m_cap) {
            int last_key = m_lists.rbegin()->first;
            m_lists.pop_back();
            hm.erase(last_key);
        }
    }
    
private:
    int m_cap;
    list<pair<int, int>> m_lists;
    unordered_map<int, list<pair<int, int>>::iterator> hm;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
