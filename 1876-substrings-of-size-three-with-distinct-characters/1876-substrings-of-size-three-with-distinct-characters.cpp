class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0;int j=0;
        map<char,int> ans;
        int a=0;
        while(j<s.size()){
            ans[s[j]]++;
            if(j-i+1<3) {j++;}
            else if(j-i+1==3){
                if(ans.size()==3) a++;
                if(ans[s[i]]==1) ans.erase(s[i]);
                else ans[s[i]]--;
                i++;j++;}
        }
        return a;
    }
};