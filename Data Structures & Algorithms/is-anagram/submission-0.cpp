class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1, map2;
        for(auto c: s){
            if(map1.find(c) != map1.end()){
                map1[c]++;
            }else{
                map1[c] = 1;
            }
        }
        for(auto c: t){
            if(map2.find(c) != map2.end()){
                map2[c]++;
            }else{
                map2[c] = 1;
            }
        }
        for(const auto& [key, count] : map1){
            if(map2[key] != count) return false;
        }
        for(const auto& [key, count] : map2){
            if(map1[key] != count) return false;
        }
        return true;
    }
};
