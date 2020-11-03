#include <bits/stdc++.h>
class Solution {
public:
    int size;
    vector<vector<vector<int>>> arr;
    vector<vector<int>> grid;
    int dp(int r1, int c1, int c2)
    {
        int r2 = r1 + c1 - c2;
        
        if(r1>=size or r2>=size or c1>=size or c2>=size or grid[r1][c1]==-1 or grid[r2][c2]==-1) return INT_MIN;
        
        else if (r1==size-1 and c1==size-1) return grid[size-1][size-1];
        
        else if (arr[r1][c1][c2] != INT_MIN) return arr[r1][c1][c2];
        
        else
        {
            int ret = grid[r1][c1];
            if(r1 != r2) ret += grid[r2][c2];
            
            int temp = max(dp(r1, c1+1, c2+1), dp(r1+1, c1, c2));
            temp = max(temp, dp(r1, c1+1, c2));
            temp = max(temp, dp(r1+1, c1, c2+1));
            
            ret += temp;
            
            return arr[r1][c1][c2] = ret;
        }
    }
    
    
    int cherryPickup(vector<vector<int>>& g) {
        
        grid = g;
        size = grid.size();
        
        vector<vector<int>> temp(size, vector<int>(size, INT_MIN));
        
        for(int i=0; i<size; i++) arr.push_back(temp);
        
        return max(0, dp(0, 0, 0));
        
    }
};