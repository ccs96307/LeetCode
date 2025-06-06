class MyHashMap {
public:
    int _size;
    vector<vector<pair<int, int>>> hashMap; 

    MyHashMap() {
        _size = 1000;
        hashMap.resize(_size, {});
    }

    int hash(int key) {
        return key % _size;   
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        bool isUpdated = false;
        for (int i=0; i<hashMap[idx].size(); ++i) {
            if (hashMap[idx][i].first == key) {
                hashMap[idx][i].second = value;
                isUpdated = true;
            }
        }

        if (!isUpdated) {
            hashMap[idx].emplace_back(key, value);
        }
    }
    
    int get(int key) {
        int idx = hash(key);

        for (int i=0; i<hashMap[idx].size(); ++i) {
            if (hashMap[idx][i].first == key) {
                return hashMap[idx][i].second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);

        for (int i=0; i<hashMap[idx].size(); ++i) {
            if (hashMap[idx][i].first == key) {
                hashMap[idx][i].second = -1;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
