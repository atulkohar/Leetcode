class Solution {
public:
    
    void merge(vector<int> &arr, int l, int m, int h)
    {
        int size1 = m-l+1, size2 = h-m;
        vector<int> left(size1),right(size2);
        for(int i=0; i<size1; i++)
            left[i] = arr[l+i];
        for(int i=0; i<size2; i++)
            right[i] = arr[i+m+1];
        int i=0,j=0,k=l;
        while(i!=size1 and j!=size2)
        {
            if(left[i] < right[j])
            {
                arr[k++] = left[i++];
            }
            else
            {
                arr[k++] = right[j++];
            }
        }
        while(i!=size1)
            arr[k++] = left[i++];
        while(j!=size2)
            arr[k++] = right[j++];
    }
    
    void mergeSort(vector<int> &arr, int start, int end)
    {
        if(start < end)
        {
            int mid = (start + end)/2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid+1, end);
            merge(arr, start, mid, end);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        vector<int> arr(nums);
        mergeSort(arr, 0, arr.size() - 1);
        return arr;
    }
};