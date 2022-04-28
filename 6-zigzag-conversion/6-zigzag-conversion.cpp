class Solution {
public:
string convert(string s, int numRows) {

    int n = s.length();
    if(numRows == 1){
        return s;
    }
    
    vector<string> v(numRows, "");
    
    int flag  = 1;
    int j = 0;
        
    for(int i=0; i<n; i++){
        v[j] += s[i];
        
        if(flag){
            j++;
        }
        else{
            j--;
        }
        
        if(j==0 || j==numRows -1){
            flag = !flag;
        }
    }
    string ans = "";
    for(int i=0; i<numRows; i++){
        ans += v[i];
    }
    return ans;
}
};