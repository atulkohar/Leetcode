class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            int find = target - numbers[i];
            int low = i + 1;
            int high = numbers.size() - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (numbers[mid] == find)
                {
                    ans.push_back(i + 1);
                    ans.push_back(mid + 1);
                    return ans;
                }
                else if (numbers[mid] < find)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};