#include <bits/stdc++.h>
using namespace std;

void check(string& s, string& q, int k, int size)
{
    if(k==0) return;
    
    int left = 0, right = 0;
    int ctr = 0, ret = 0;
    
    while(right < size)
    {
        while(ctr<k && right<size)
        {
            if(q[s[right]-'a'] == '0') ctr++;
            
            right++;
            
            ret = max(ret, right-left+1);
        }
        
        // ret = max(ret, right-left+1);
        
        while(left<right)
        {
            if(q[s[left]-'a'] == '0') ctr--;
            left++;
            if(ctr<k) break;
        }
    }
    
    cout<<ret;
}

int main() {
    
	string P = "giraffe", Q = "01111001111111111011111111"; 
  
    int K = 2; 
  
    int N = P.length();
    
    check(P, Q, N, K);
    
	return 0;
}
