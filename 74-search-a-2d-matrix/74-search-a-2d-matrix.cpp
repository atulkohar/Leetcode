class Solution {
public:
    
    bool binarySearch(vector<int> v, int x)
    {
        int i=0, j=v.size()-1;
        while(i<=j)
        {
            int m = (i+j)/2;
            if(v[m] == x)
                return true;
            else if(v[m] < x)
                i = m+1;
            else
                j = m-1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = 0;
        while(i < n)
        {
            int size = matrix[i].size();
            if(matrix[i][size-1] >= target)
            {
                return binarySearch(matrix[i],target);
            }
            i++;
        }
        return false;
    }
};