class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        vector<int>r;

        for(int i:a)
        {
            bool t=true;
            while(!s.empty() && i<0 && s.top()>0)
            {
                if(s.top() < -i)
                {
                    s.pop();
                }
                else if(s.top() == -i)
                {
                    t=false;
                    s.pop();
                    break;
                }
                else
                {
                    t=false;
                    break;
                }
            }
            if(t)
                s.push(i);
        }
        while(!s.empty())
        {
            r.push_back(s.top());
            s.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    }
};