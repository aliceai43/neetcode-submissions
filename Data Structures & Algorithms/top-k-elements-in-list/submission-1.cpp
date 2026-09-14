class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        int n = nums.size();       
        unordered_map<int, int> m;
        for(auto n : nums){
            if(m.find(n) != m.end()){
                m[n]++;
            }else{
                m[n] = 1;
            }
        }
        vector<vector<int>> bucket(n + 1);
        for(auto& [num, count] : m){
            bucket[count].push_back(num);
        }

        vector<int> result;
        for(int i = n; i >= 0; i--){
            for(int num: bucket[i]){
                result.push_back(num);
            }
            if(result.size() == k) return result;
        }


        return result;
    }
};
