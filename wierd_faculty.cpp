#include <bits/stdc++.h>
using namespace std;

int main() {
    
	vector<int> arr{1, 1, 1, 0, 1};
	
	int size = arr.size();
	
	int total = 0;
	
	for(auto x : arr) 
	{
	    if(x == 0) total += -1;
	    else total += 1;
	}
	
	int cur = 0, idx = 0;
	
	for(int i=0; i<size; i++)
	{
	    if(cur > total)
	    {
	        idx = i;
	        break;
	    }
	    cur += arr[i]==0 ? -1 : 1;
	    total -= arr[i]==0 ? -1 : 1;
	}
    cout<<idx;
	return 0;
}
