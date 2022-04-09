class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        int first=0,second=1,third=1;
        for(int i=4;i<=n;i++){
            int a=first,b=second;
            first=second;
            second=third;
            third+=a+b;
           
        }
        return first+second+third;
    }
};