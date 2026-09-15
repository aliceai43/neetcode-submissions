class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1, len = 1;
        int pre = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]) continue;
            if ( nums[i] == pre + 1) {
                len++;
                pre = nums[i];
            }else if ( nums[i-1] != nums[i]){
                len = 1;
                pre = nums[i];
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
