#include <bits/stdc++.h>

class Solution{   
public:
    int lenghtOfLongestAP(int set[], int n) {
    
        if(n<3) return n;
        
        int ret = 2;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) dp[i][n-1] = 2;
        
        for(int j=n-2; j>=1; j--)
        {
            int i = j-1, k = j+1;
            
            while(i>=0 && k<n)
            {
                if(set[i] + set[k] > 2*set[j]) 
                {
                    dp[i][j] = 2;
                    i--;
                }
                
                else if (set[i] + set[k] < 2*set[j]) k++;
                
                else
                {
                    dp[i][j] = 1 + dp[j][k];
                    
                    ret = max(ret, dp[i][j]);
                    
                    i--;
                    k++;
                }
            }
            
            while(i>=0) dp[i--][j] = 2;
        }
        
        return ret;
    }
};