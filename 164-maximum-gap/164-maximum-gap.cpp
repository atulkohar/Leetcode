class Solution {
public:
  void countsort(vector<int> &arr, int n, int exp)
  {
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
      count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
      count[i] += count[i - 1];
    }

    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
      ans[--count[(arr[i] / exp) % 10]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
      arr[i] = ans[i];
    }
  }
    int maximumGap(vector<int>& nums) {
       int n = nums.size();
       if(n < 2)
       return 0;
       int maxval = nums[0];
       for (int i = 1; i < n; i++)
       {
         maxval = max(maxval, nums[i]);
       }
       int exp = 1;
       while (exp <= maxval)
       {
         countsort(nums, n, exp);
         exp = exp * 10;
       }
       int diff = 0;
       for (int i = 1; i < n; i++)
       {
         diff = max(diff, nums[i] - nums[i-1]);
       }
       return diff;
    }
};