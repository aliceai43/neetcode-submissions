class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>  m;
        for (int i = 0; i < position.size(); i++){
            m.push_back({position[i], (double(target-position[i]))/double(speed[i])});
        }
        sort(m.begin(), m.end(), [](auto a, auto b){
            return a.first > b.first;
        });

        stack<double> st;
        for (int i = 0; i < m.size(); i++){
            if (!st.empty() && m[i].second > st.top()) {
                st.push(m[i].second);
            }else if (st.empty()){
                st.push(m[i].second);
            }
        }

        return st.size();

    }
};

