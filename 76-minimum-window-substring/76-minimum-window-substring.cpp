class Solution {
public:
    string minWindow(string s, string t)
    {
        int ns=s.length(),nt=t.length();
        int c=0,beg=0;
        int mn=INT_MAX,in=-1;        
        int i;
        unordered_map<char,int> m;
        
        for(i=0;i<nt;i++)
            m[t[i]]++;
        
        for(i=0;i<ns;i++)
        {
            m[s[i]]--;
            
            if(m[s[i]]>=0)
                c++;
            
            while(c==nt && beg<=i)
            {
                if(i-beg+1<mn)
                {
                    mn=i-beg+1;
                    in=beg;
                }
                
                m[s[beg]]++;
                if(m[s[beg]]>0)
                    c--;
                
                beg++;
            }
        }
        
        if(mn==INT_MAX)
            return "";
        
        return s.substr(in,mn);
    }
};