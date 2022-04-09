class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i] != t[j]){
                    int cnt1 = 0, cnt2 = 0;
                    int ips = i - 1, ipt = j - 1, ifs = i + 1, ift = j + 1;
                    while(ips >= 0 && ipt >= 0 && s[ips] == t[ipt]){
                        cnt1++, ips--, ipt--;
                    }
                    while(ifs < n && ift < m && s[ifs] == t[ift]){
                        cnt2++, ifs++, ift++;
                    }
                    ans += cnt1 * cnt2 + cnt1 + cnt2 + 1;
                }
            }
        }
        return ans;
    }
};