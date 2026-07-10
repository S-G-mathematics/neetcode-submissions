class MyHashMap {
private:
    vector<int> keys;
    vector<int> values;

public:
    MyHashMap() {

    }

    void put(int key, int value) {
        auto it = find(keys.begin(), keys.end(), key);

        if (it != keys.end()) {
            values[it - keys.begin()] = value;
        } else {
            keys.push_back(key);
            values.push_back(value);
        }
    }

    int get(int key) {
        auto it = find(keys.begin(), keys.end(), key);

        if (it != keys.end())
            return values[it - keys.begin()];

        return -1;
    }

    void remove(int key) {
        auto it = find(keys.begin(), keys.end(), key);

        if (it != keys.end()) {
            int idx = it - keys.begin();   // Save index before erase
            keys.erase(keys.begin() + idx);
            values.erase(values.begin() + idx);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key, value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */