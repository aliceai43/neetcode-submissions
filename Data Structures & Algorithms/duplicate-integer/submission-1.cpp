class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> h;
        for(auto i : nums){
            if(h.count(i)){
                return true;
            }
            h.insert(i);
        }
        return false;
    }
};