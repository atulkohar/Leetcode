class Solution {
public:

      //find pivot o(log n)
       int find_Pivot(vector <int> &arr)
            {
              int start=0; int end=arr.size()-1;
             while(start<end){
                int mid = (start+end)/2;
                if(arr[mid]>=arr[end]) start=mid+1;
                 else end=mid;
              }
               return start;
           }
         
         int findMin(vector<int>& nums){
               int n=nums.size();
                int pivot=find_Pivot(nums);
                 return nums[pivot];
         }
         // }
};