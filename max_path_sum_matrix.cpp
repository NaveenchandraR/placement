#include <bits/stdc++.h>
class Solution{
public:
    
    int row, col;
    vector<vector<int>> grid;
    
    int dp(vector<vector<int>>& arr, int r, int c)
    {
        if(c<0 or c>=col) return 0;
        if(r == row) return 0;
        if(grid[r][c] != -1) return grid[r][c];
        
        int ans = 0;
        for(int temp=c-1; temp<=c+1; temp++)
        {
            ans = max(ans, dp(arr, r+1, temp));
        }
        ans += arr[r][c];
        
        return grid[r][c] = ans;
    }

    int maximumPath(int N, vector<vector<int>> arr)
    {
        row = arr.size();
        col = arr[0].size();
        
        vector<vector<int>> temp(row, vector<int>(col, -1));
        grid = temp;
        int ans = 0;
        for(int i=0; i<col; i++)
            ans = max(ans, dp(arr, 0, i));
            
        return ans;
        
    }
};