class Solution {
public:
    string multiply(string num1, string num2) {
        int temp[500] = {0};
        int carry = 0;
        int k = 0;
        int shift=0;
        int size = 0;
        for(int i=num1.size()-1;i>=0;i--){
            k = 0;
            for(int j=num2.size()-1;j>=0;j--){
                int r = ((num1[i]-'0')*(num2[j]-'0') + carry) +temp[k+shift];
                temp[k+shift] = r%10;
                carry = r/10;
                k++;
            }
            size = shift + k;
            if(carry!=0){
                temp[k+shift] = carry;
                size = shift + k+1;
            }
            shift++;
            carry=0;
        }
        string ans="";
        for(int i=size-1;i>=0;i--){
            ans+=to_string(temp[i]);
        }
        if(ans[0]=='0')
            return "0";
        return ans;
        
    }
};