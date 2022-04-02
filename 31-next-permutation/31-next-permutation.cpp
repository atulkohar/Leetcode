class Solution
{
public:
    void reverse(vector<int> &arr, int s, int e)
    {
        while(s < e)
        {
            swap(arr[s++] , arr[e--]);
        }
    }
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size();
        int ind1 = -1, ind2 = -1;
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i] < arr[i+1])
            {
                ind1 = i;
                break;
            }
        }
        if(ind1 == -1)
        {
            reverse(arr,0,n-1);
            return;
        }
        for(int i=ind1+1; i<n; i++)
        {
            if(arr[i] > arr[ind1])
            {
                ind2 = i;
            }
        }
        swap(arr[ind1],arr[ind2]);
        reverse(arr,ind1+1,n-1);
    }
};