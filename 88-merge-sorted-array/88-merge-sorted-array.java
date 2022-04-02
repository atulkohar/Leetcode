class Solution
{
public
    void merge(int[] nums1, int m, int[] nums2, int n)
    {
        int c = 0, d = 0, p = -1, i;
        if (m != 0 && n != 0)
        {
            int[] arr = new int[m + n];
            while (c < m && d < n)
            {
                if (nums1[c] < nums2[d])
                {
                    arr[++p] = nums1[c];
                    c++;
                }
                else if (nums1[c] > nums2[d])
                {
                    arr[++p] = nums2[d];
                    d++;
                }
                else if (nums1[c] == nums2[d])
                {
                    arr[++p] = nums1[c];
                    arr[++p] = nums2[d];
                    c++;
                    d++;
                }
            }
            if (c == m)
            {
                for (i = d; i < n; i++)
                {
                    arr[++p] = nums2[i];
                }
            }
            else if (d == n)
            {
                for (i = c; i < m; i++)
                {
                    arr[++p] = nums1[i];
                }
            }
            for (i = 0; i < nums1.length; i++)
            {
                nums1[i] = arr[i];
            }
        }
        else if (m == 0)
        {
            for (int j = 0; j < n; j++)
            {
                nums1[j] = nums2[j];
            }
        }
    }
}