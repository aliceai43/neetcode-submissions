class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> h;
        for(auto i : nums){
            if(h.find(i) != h.end()){
                return true;
            }else{
                h[i] = true;
            }
        }
        return false;
    }
};