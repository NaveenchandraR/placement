#include <bits/stdc++.h>
using namespace std;


int mini(vector<int>& arr, vector<vector<int>>& dp, int start, int end, int k)
{
    if(dp[start][end] != -1) return dp[start][end];
    
    if(end-start+1 < 3) return end-start+1;
    
    int res = 1 + mini(arr, dp, start+1, end, k);
    
    for(int i=start+1; i<end; i++)
        for(int j=i+1; j<=end; j++)
        {
            if (arr[i]==arr[start]+k &&
                arr[j]==arr[start]+2*k &&
                mini(arr, dp, start+1, i-1, k) == 0 &&
                mini(arr, dp, i+1, j-1, k) == 0)
                
                {
                    res = min(res, mini(arr, dp, j+1, end, k));
                }
        }
        
    return dp[start][end] = res;
}

int main() {
    
    vector<int> arr{2, 3, 4, 5, 6, 4};
    int size = arr.size();
    int k = 1;
    
    vector<vector<int>> dp(size+1, vector<int>(size+1, -1));
    
    cout<<mini(arr, dp, 0, size-1, k);

	return 0;
}