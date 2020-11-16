#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr)
{
    int size = arr.size();
    int a = 0, b = 0, c = 0;
    
    for(int i=0; i<size; i++)
    {
        if(arr[i]%3 == 0) a++;
        
        else if (arr[i]%3 == 1) b++;
        
        else if (arr[i]%3 == 2) c++;
    }
    
    if(a>=1 && a <= b+c+1) return true;
    if(a==0 && b==0 && c>0) return true;
    if(a==0 && c==0 && b>0) return true;
    
    else return false;
}

int main() {
	
	vector<int> arr{};
	cout<<check(arr);
	
	return 0;
}
