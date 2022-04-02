class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();

        int lo = -1, hi = n - 1;
        int even = ((n + m) & 1) ^ 1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            int r = n - mid - 1;
            int needed = (n + m) / 2 - r;
            if (needed < 0)
            {
                lo = mid + 1;
                continue;
            }
            if (needed > m)
            {
                hi = mid - 1;
                continue;
            }

            int i = mid;
            int j = m - needed - 1;

            int left_max = i > -1 ? A[i] : INT_MIN;
            if (j >= 0)
                left_max = max(left_max, B[j]);

            int right_min = min(j + 1 >= m ? INT_MAX : B[j + 1], i + 1 >= n ? INT_MAX : A[i + 1]);
            if (left_max <= right_min)
            {
                double median = left_max;
                if (even)
                {
                    median += right_min;
                    return median / 2;
                }
                else
                    return median;
            }
            else
            {
                if (i > -1 && left_max == A[i])
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
        }

        return -1;
    }
};