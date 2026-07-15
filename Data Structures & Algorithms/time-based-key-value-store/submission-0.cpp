class TimeMap {
private:
    unordered_map<string, set<pair<int,string>>> q;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        q[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(q.find(key) == q.end())
            return "";

        auto it = q[key].upper_bound({timestamp, string(1, char(127))});

        if(it == q[key].begin())
            return "";

        --it;
        return it->second;
    }
};