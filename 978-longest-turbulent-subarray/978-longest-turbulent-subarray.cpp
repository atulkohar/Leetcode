class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 1;
        int i, ans = 1, n = arr.size() - 1, curr = 1;
        bool less = arr[0] < arr[1] ? true : false;
        for (i = 0; i < n; ++i)
        {
            ans = max(ans, curr);
            if ((less and arr[i] < arr[i + 1]) or (!less and arr[i] > arr[i + 1]))
                ++curr;
            else
            {
                while (i < n and arr[i] == arr[i + 1])
                    ++i;
                if (i == n)
                    break;
                curr = 2;
                less = arr[i] < arr[i + 1] ? true : false;
            }
            less = less ? false : true;
        }
        return max(ans, curr);
    }
};