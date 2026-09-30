class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int ans = 1, p = -1;
        map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] < p) ans = max(ans, i-p);
                else ans = max(ans, i-m[s[i]]);
                p = max(m[s[i]], p);
            }else{
                ans = max(ans, i-p);
            }
            m[s[i]] = i;
        }
        return ans;
    }
};
