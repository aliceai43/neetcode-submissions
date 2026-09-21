class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, ans = 0;
        int leftMax = 0, rightMax = 0;
        while (l < r){
            int i = min(height[l], height[r]);
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            
            ans += min(leftMax, rightMax) - i;

            if (height[l] < height[r]) l++;
            else r--;
        }

        return ans;
    }
};
