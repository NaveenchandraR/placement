#include <bits/stdc++.h>
using namespace std;

int check (string s)
{
    int len = s.length();
    vector<int> count(256, -1);
    
    vector<int> dp(len+1, 0);
    dp[0] = 1;
    
    for(int i=1; i<=len; i++)
    {
        dp[i] = 2*dp[i-1];
        
        if(count[s[i-1]]!=-1)
            dp[i] -= dp[count[s[i-1]]];
            
        count[s[i-1]] = i-1;
    }
    
    return dp[len];
}

int main() {
	cout<<check("gfg");
	return 0;
}