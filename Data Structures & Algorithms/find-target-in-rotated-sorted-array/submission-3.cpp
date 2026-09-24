class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if (nums[0] == target) return l;
        if (nums[r] == target) return r;
        while (l < r){
            int mid = (l+r)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] <= nums[0] && (target <= nums[mid] || target >= nums[0])) r = mid;
            else if (nums[mid] >= nums[0] && (target >= nums[0] && target <= nums[mid])) r = mid;
            else l = mid + 1;
        }
        // cout << l <<" "<< r << endl;
        if (nums[l] == target) return l;
        return -1;
    }
};
