class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 1; i <= numRows; i++) {
            triangle.push_back(vector<int>(i));
            triangle[i - 1].front() = 1;
            triangle[i - 1].back() = 1;
        }
        
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        
        return triangle;
    }
};