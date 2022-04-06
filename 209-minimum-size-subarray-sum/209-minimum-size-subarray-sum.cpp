class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        long long sum = 0, st = 0, mn = LLONG_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (st < i && sum > target)
            {
                sum -= nums[st];
                if (sum < target)
                {
                    sum += nums[st];
                    break;
                }
                st++;
            }
            if (sum >= target)
            {
                mn = min(i - st + 1, mn);
            }
        }
        if (mn == LLONG_MAX)
        {
            return 0;
        }
        return mn;
    }
};