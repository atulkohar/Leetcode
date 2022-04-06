class Solution
{
public:
    int majorityElement(vector<int> &A)
    {
        int cand = A[0];
        int count = 1;

        int n = A.size();
        for (int i = 1; i < n; i++)
        {
            if (A[i] == cand)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    cand = A[i];
                    count = 1;
                }
            }
        }
        /// we can not assume , so we check
        int count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == cand)
            {
                count2++;
            }
        }

        if (count2 > n / 2)
            return cand;
        else
            return -1;
    }
};