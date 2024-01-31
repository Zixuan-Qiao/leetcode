class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        bool even;
        int n;
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            even = true;
            n = (nums1.size() + nums2.size()) / 2 + 1;
        }
        else {
            even = false;
            n = (nums1.size() + nums2.size() + 1) / 2;
        }

        vector<int> m;
        int p1 = 0;
        int p2 = 0;
        while(p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) {
                m.push_back(nums1[p1]);
                p1++;
            }
            else if (nums1[p1] > nums2[p2]) {
                m.push_back(nums2[p2]);
                p2++;
            }
            else {
                m.push_back(nums1[p1]);
                p1++;
            }
        }

        if (m.size() < n && p1 == nums1.size()) {
            while (m.size() < n) {
                m.push_back(nums2[p2]);
                p2++;
            }
        }
        else if (m.size() < n && p2 == nums2.size()) {
            while (m.size() < n) {
                m.push_back(nums1[p1]);
                p1++;
            }
        }

        if (even) {
            return (m[n - 2] + m[n - 1]) / 2.0;
        } else
            return m[n - 1];
    }       
};