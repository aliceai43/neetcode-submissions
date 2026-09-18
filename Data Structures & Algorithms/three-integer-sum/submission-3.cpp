class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size()-1;
            while(l < r){
                int s = nums[i] + nums[l] + nums[r];
                if (s == 0) {
                    ans.push_back(vector<int> {nums[i], nums[l], nums[r]} );

                    while (r > l && nums[r-1] == nums[r])r--;
                    while (r > l && nums[l] == nums[l+1])l++;
                    l++;
                    r--;
                }
                else if (s > 0) r--;
                else l++;
            }
        }
        return ans;
    }
};
