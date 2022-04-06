class Solution {
public:
    int res=0;
    void solve(int i, int j, vector<vector<char>> &g)
    {
        if(i>=0 && i<g.size() && j>=0 && j<g[0].size() && g[i][j] == '1') // stretch this one island as much as you can till it get out of bounds 
        {
            g[i][j] = '2'; // mark it as visited so in future u dont use this cell for some other island
            solve(i+1, j, g); // simply moving in down 
            solve(i, j+1, g); // right
            solve(i-1, j, g); // up
            solve(i, j-1, g); // and left direction.
        }
    }
    int numIslands(vector<vector<char>> &g) 
    { // Traversing entire matrix for finding '1' that represent your island
        for(int i=0; i<g.size(); i++) 
            for(int j=0; j<g[0].size(); j++)
                if(g[i][j]=='1') // Valid Candidate
                    solve(i, j, g), res++; // Apply DFS, increment result by 1 as u found one island
        return res;
    }
};