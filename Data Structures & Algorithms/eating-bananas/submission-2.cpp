class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int s = piles.size() -1, ans = piles[s];
        int l = 1, r = piles[s];
        while (l <= r) {
            int mid = (l+r)/2;
            auto it = upper_bound(piles.begin(), piles.end(), mid)-piles.begin();
            int t = it;
            for (int j = it; j < piles.size(); j++){
                t += (piles[j]+mid-1)/mid;
                if (t > h) break;
            }
            if (t <= h) {
                r = mid - 1;
                ans = min(ans, mid);
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
