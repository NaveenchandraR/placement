#include <bits/stdc++.h>
using namespace std;

int main() {
    
	string s = "wwwbbbbwww";
	int size = s.length();
	
	int w=0, b=0;
	
	int left = 0, ctr = 0;
	
	while(left < size)
	{
	    if(s[left] == s[left+1])
	    {
	        ctr = 0;
	        while(s[left] == s[left+1] && left<size-1)
	        {
	            left++;
	            ctr++;
	        }
	        if(ctr-1 > 0)
	        {
	            if(s[left] == 'w') w+=ctr-1;
	            else b+=ctr-1;
	        }
	    }
	    left++;
	}
	
	if(w <= b) cout<<"wendy";
	else cout<<"bob";
	
	return 0;
}
