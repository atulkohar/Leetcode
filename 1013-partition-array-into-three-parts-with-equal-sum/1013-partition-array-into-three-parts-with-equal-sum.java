class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int sum= 0;
        
        for(int i = 0;i<arr.length;i++)
        {
            sum=sum+arr[i];
        }
        if(sum%3 != 0)
            return false;
        //sum of each partition is 1/3 of final sum
        sum=sum/3;
        int partition=0;
        int currentSum = 0;
        //make 3 partitions
        for(int i=0;i<arr.length;i++)
        {
            currentSum=currentSum+arr[i];
            if(currentSum==sum && partition<3)
            {
                partition++;
                currentSum=0;
            }
        }
        //if we are able to make 3 partitions we can partition the array equally
        return (partition==3);
    }
}