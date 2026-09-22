class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1, n = matrix[0].size()-1, l = 0, r = m, mid;
        
        if (target < matrix[0][0]) return false;

        if (target > matrix[m][0]){
            l = 0; r = n;
            mid = (l+r)/2;
            while (mid > l && mid < r){
                if (target == matrix[m][mid]) return true;
                if (target > matrix[m][mid]) l = mid;
                else r = mid;
                mid = (l+r)/2;
            }  
            if (target == matrix[m][mid] || target == matrix[m][r]) return true;
        }
        l = 0; 
        r = m;
        mid = (l+r)/2;
        while (mid > l && mid < r) {
            if (target == matrix[mid][0]) return true;
            if (target > matrix[mid][0]) l = mid;
            else r = mid;
            mid = (l+r)/2;
        }
        int row = l;
        if (target == matrix[r][0]) return true;
        l = 0; r = n;
        mid = (l+r)/2;
        while (mid > l && mid < r){
            if (target == matrix[row][mid]) return true;
            if (target > matrix[row][mid]) l = mid;
            else r = mid;
            mid = (l+r)/2;
        }            
        if (target == matrix[row][mid] || target == matrix[row][r]) return true;
        return false;
    }
};
