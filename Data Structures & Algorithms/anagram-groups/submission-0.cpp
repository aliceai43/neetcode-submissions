class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        vector<vector<string>> result;
        
        for(const auto& s: strs){
            vector<int> count(26, 0);
            for(auto c: s){
                count[c-'a']++;
            }
            string k = to_string(count[0]);
            for(int i = 1; i < 26; i++){
                k += ',' + to_string(count[i]);
            }
            res[k].push_back(s);
           
        }
        for(const auto& pair : res ){
            result.push_back(pair.second);
        }
        return result;
    }
};
