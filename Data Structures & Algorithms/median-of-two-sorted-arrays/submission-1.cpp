class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size()-1, len2 = nums2.size()-1;
        int i1 = 0, i2 = 0, m1 = 0, m2 = 0;
        for (int i = 0; i < (len1+len2+2)/2 + 1; i++){
            m2 = m1;
            if (i1 <= len1 && i2 <= len2){
                if (nums1[i1] < nums2[i2]){
                    m1 = nums1[i1];
                    i1++;
                }else{
                    m1 = nums2[i2];
                    i2++;
                }
            }else if (i1 <= len1){
                m1 = nums1[i1];
                i1++;
            }else{
                m1 = nums2[i2];
                i2++;
            }
        }
        if ( (len1 + len2) % 2 == 0) return (m1+m2)/2.0;
        return double(m1);

    }
};


// 4 5 8 9
// 1 7 13 19 20

