class Solution
{
public:
    int countPrimes(int n)
    {
        bool prime[n + 1];
        int res = 0;
        for (int i = 0; i < n+1; i++)
        {
            prime[i] = true;
        }
        for (int i = 2; i * i < n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n; j = j + i)
                {
                    prime[j] = false;
                }
            }
        }

        for (int i = 2; i < n; i++)
        {
            if (prime[i])

                res++;
        }
        return res;
    }
};