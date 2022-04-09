class Solution {
public:
    int countSubstrings(string s, string t) 
    {
        int res=0;
        int n=s.size(),m=t.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i]!=t[j])
                {
                    int l=1,r=1;
                    while(min(i-l,j-l)>=0&&s[i-l]==t[j-l])
                        l++;
                    while(i+r<n&&j+r<m&&s[i+r]==t[j+r])
                        r++;
                    res+=l*r;
                }
            }
        }
        return res;
        
    }
};