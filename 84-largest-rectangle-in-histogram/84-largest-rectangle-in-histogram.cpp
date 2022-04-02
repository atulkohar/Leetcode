class Solution {
public:
    int largestRectangleArea(vector<int> &arr) {
        int i=0,n=arr.size();
        int ele=0, ans=0;
        stack<int> s;
        while(i<n)
        {
            if(s.empty() or arr[s.top()] <= arr[i])
            {
                s.push(i++);
            }
            else
            {
                int top = s.top();
                s.pop();
                ele = arr[top]*(s.empty()?i:i-s.top()-1);
                ans = max(ans,ele);
            }
        }
        while(s.empty() == false)
        {
            int top = s.top();
            s.pop();
            ele = arr[top]*(s.empty()?i:i-s.top()-1);
            ans = max(ans,ele);
        }
        return ans;
    }
};