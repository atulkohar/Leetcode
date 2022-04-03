class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens[0]=="+"||tokens[0]=="-"||tokens[0]=="*"||tokens[0]=="/")
            return -1;
        stack<int> s;
        s.push(stoi(tokens[0]));
        for(int i=0;i<tokens.size();i++)
        {
            string curr = tokens[i];
            if(curr=="+"||curr=="-"||curr=="*"||curr=="/")
            {
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                int res;
                if(curr=="+")
                    res = v2+v1;
                else if(curr=="-")
                    res = v2-v1;
                else if(curr=="*")
                    res = v2*v1;
                else if(curr=="/")
                    res = v2/v1;
                s.push(res);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};