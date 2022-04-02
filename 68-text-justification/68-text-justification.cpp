class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> lens;
        for(auto w:words)
        {
            lens.push_back(w.length());
        }
        vector<vector<string>> store_strings(words.size());
        vector<int> line_sum(words.size());
        int line = 0;
        int iterator = 0;
        while(iterator<words.size())
        {
            int sum = 0;
            while(sum<maxWidth and iterator<words.size())
            {
                if((sum + lens[iterator])<=maxWidth)
                {
                    store_strings[line].push_back(words[iterator]);
                    sum += lens[iterator];
                    line_sum[line] += lens[iterator];
                    if(sum!=maxWidth)
                    {
                        sum++;
                    }
                    iterator++;
                    //cout<<iterator<<" "<<endl;
                }
                else
                    break;
            }
            //cout<<iterator<<"asdsf"<<endl;
            line++;
        }
        vector<string> result;
        for(int i=0;i<line;i++)
        {
            string ans = "";
            int space;
            int extras;
            if(store_strings[i].size()!=1 and i!=line-1)
            {
                space = (maxWidth-line_sum[i])/(store_strings[i].size()-1);
                extras = (maxWidth-line_sum[i])%(store_strings[i].size()-1);
            }
            else if(i!=line-1)
            {
                space = (maxWidth-line_sum[i]);
                extras = 0;
            }
            
            for(int j=0;j<store_strings[i].size();j++)
            {
                if(i==line-1 and j!=store_strings[i].size()-1)
                {
                    ans += store_strings[i][j] + " ";
                }
                else if(i==line-1)
                {
                    ans += store_strings[i][j];
                    int fill = maxWidth - ans.size();
                    for(int k=0;k<fill;k++)
                        ans += " ";
                }
                else if(i!=line-1 and j!=store_strings[i].size()-1)
                {
                    ans += store_strings[i][j];
                    for(int k=0;k<space;k++)
                        ans +=" ";
                    if(j<extras)
                        ans+=" ";
                }
                else
                {
                    ans += store_strings[i][j];
                    while(ans.size()!=maxWidth)
                        ans +=" ";
                }
            }
            result.push_back(ans);
        }
        
        return result;
        
    }
};