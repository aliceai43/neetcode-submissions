class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), pos(n), output(n);
        int j = nums[0], k = nums[n-1];
        pre[0] = 1;
        pos[n-1] = 1;
        for(int i = 1; i < nums.size(); i++){
            pre[i] = j;
            j *= nums[i];
            pos[n-i-1] = k;
            k *= nums[n-i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            output[i] = pre[i]*pos[i];
        }
        return output;
    }
};
