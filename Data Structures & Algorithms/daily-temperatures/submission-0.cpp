class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size(), 0);
        stack<pair<int, int>> st;
        st.push({temps[0], 0});
        for (int i = 1; i < temps.size(); i++){
            while(!st.empty() && st.top().first < temps[i]){
                ans[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temps[i], i});
        }
        return ans;
    }
};
