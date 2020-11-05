#include <bits/stdc++.h>
using namespace std;

int main() {
    
	string s = "wwwbbbbwwwww";
	int size = s.length();
	
	priority_queue<int> w, b;
	
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
	            if(s[left] == 'w') w.push(ctr-1);
	            else b.push(ctr-1);
	        }
	    }
	    left++;
	}
	
	
	
	return 0;
}
