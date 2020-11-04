#include <bits/stdc++.h>
using namespace std;

int main() {
    
	vector<int> arr{5, 3, 2, 4, 1, 2};
	
	int size = arr.size();
	
	int total = 0;
	
	for(auto x : arr) total += x;
	
	sort(arr.begin(), arr.end(), greater<int>());
	
	int count = 0, itr = 0;;
	for(int i=0; i<size; i++)
	{
	    count += arr[i];
	    total -= arr[i];
	    
	    if(count > total)
	    {
	        itr = i;
	        break;
	    }
	}
	
	for(int i=itr; i>=0; i--) cout<<arr[i]<<" ";
	return 0;
}
