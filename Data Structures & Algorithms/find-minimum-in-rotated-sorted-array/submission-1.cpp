class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        if (nums[l] < nums[r]) return nums[l];
        while (l < r && l >= 0 && r >= 0) {
            int mid = (l+r)/2;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};
