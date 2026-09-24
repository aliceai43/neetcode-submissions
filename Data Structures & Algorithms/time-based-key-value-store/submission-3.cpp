class TimeMap {
public:
    vector<vector<pair<int, string>>> st;
    map<string, int> names;
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        if (names.find(key) != names.end()){
            st[names[key]].push_back({timestamp, value});
        }else {
            names[key] = st.size();
            st.push_back({{timestamp, value}});
        }
    }
    
    string get(string key, int timestamp) {
        if (names.find(key) == names.end()) return "";
        int l = 0, r = st[names[key]].size() - 1;
        string ans = "";
        if (timestamp > st[names[key]][r].first) return st[names[key]][r].second;
        if (timestamp < st[names[key]][l].first) return "";
        while (l < r) {
            int mid = (l+r)/2;
            if (st[names[key]][mid].first <= timestamp){
                ans = st[names[key]][mid].second;
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        if (st[names[key]][l].first <= timestamp )ans = st[names[key]][l].second;
        return ans;
    }
};
