class Solution {
public:
    int largestRectangleArea(vector<char>& heights) {
        
        stack<int> s;
        int res=0,curr;
        
        for(int i=0;i<heights.size();i++){
            while(s.empty()==false && heights[s.top()]>=heights[i]){
                int tp=s.top();
                s.pop();
                curr=heights[tp]*(s.empty()?i:(i-s.top()-1));
                res=max(curr,res);
            }
            s.push(i);
        }
        while(!s.empty()){
            int tp=s.top();
            s.pop();
            curr=heights[tp]*(s.empty()?heights.size():(heights.size()-s.top()-1));
            res=max(curr,res);
        }
        return res;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        bool isAll1=true;
        
        //char to int
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=matrix[i][j]-48;
                if(matrix[i][j]==0)
                    isAll1=false;
            }
        }
        if(isAll1)
            return matrix.size()*matrix[0].size();
       int res=largestRectangleArea(matrix[0]);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
            res=max(res,largestRectangleArea(matrix[i]));
        }
        return res;
    }
};
