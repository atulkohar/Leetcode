class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        int i = 0, j = 0, ctr = 0;
        while(i < n1 and j < n2){
            if(s[i] == t[j]){
                ctr++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(ctr == n1){
            return true;
        }
        return false;
    }
};