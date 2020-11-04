#include <bits/stdc++.h>
using namespace std;

int main() {
    
	vector<int> arr{3, 5, 2, 4, 6, 8};
	
	int size = arr.size();
	
	vector<pair<int, int>> vec(size);
	
	for(int i=0; i<size; i++)
	{
	    vec[i].first = arr[i];
	    vec[i].second = i;
	}
	
	sort(vec.begin(), vec.end());
	
	int ans = 0;
	
	for(int i=0; i<size; i++)
	{
	    if(vec[i].second == i) continue;
	    
	    else
	    {
	        swap(vec[i].first, vec[vec[i].second].first);
	        swap(vec[i].second, vec[vec[i].second].second);
	    }
	    
	    if(vec[i].second != i) i--;
	    
	    ans++;
	}
	
	cout<<ans;
    
	return 0;
}
