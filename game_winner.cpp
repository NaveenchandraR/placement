#include <bits/stdc++.h>
using namespace std;

int main() {
    
	string s = "wwwbbbbwww";
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
	
	if(w.empty()) cout<<"wendy";
	if(b.empty()) cout<<"bob";
	
	int curr = 1, temp = 0;
	//1 for wendy
	//0 for bob
	
	while(!w.empty() && !b.empty())
	{
	    if(curr == 1)
	    {
	        temp = w.top()-1;
	        w.pop();
	        if(temp>0) w.push(temp);
	        curr = 0;
	    }
	    
	    else
	    {
	        temp = b.top()-1;
	        b.pop();
	        if(temp>0) b.push(temp);
	        curr = 1;
	    }
	}
	
	if(curr == 1)
	{
	    if(w.size()>0) cout<<"bob";
	    else cout<<"wendy";
	}
	
	else
	{
	    if(b.size()>0) cout<<"wendy";
	    else cout<<"bob";
	}
	
	return 0;
}
