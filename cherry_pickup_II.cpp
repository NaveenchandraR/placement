#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<vector<int>>> arr;
    int row, col;
    
    int dp(vector<vector<int>>& grid, int r, int c1, int c2)
    {
        if(c1<0 or c2<0 or c1>=col or c2>=col) return 0;
        if(r == row) return 0;
        if(arr[r][c1][c2] != -1) return arr[r][c1][c2];
        
        int ans = 0;
        for(int nc1=c1-1; nc1<=c1+1; nc1++)
            for(int nc2=c2-1; nc2<=c2+1; nc2++)
            {
                ans = max(ans, dp(grid, r+1, nc1, nc2));
            }
        
        int cherry = (c1==c2) ? grid[r][c1] : grid[r][c1]+grid[r][c2];
        
        return arr[r][c1][c2] = cherry + ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        row = grid.size();
        col = grid[0].size();
        
        vector<vector<int>> temp(70, vector<int>(70, -1));
        for(int i=0; i<70; i++) arr.push_back(temp);
        
        return dp(grid, 0, 0, col-1);
    }
};