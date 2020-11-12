#include <bits/stdc++.h>
using namespace std;


long minoperations(vector<int>& arr)
{
    long count = 0;
    
    int left = 0;
    int right = 0;
    vector<int> target;
    int size = arr.size();
    
    for(int i=0; i<size; i++)
    {
        left = 0;
        right = 0;
        for(int j=0; j<target.size(); j++)
        {
            if(arr[i] != arr[j])
            {
                if(i != j)
                {
                    if(arr[i]<arr[j]) left++;
                    
                    else right++;
                }
            }
        }
        
        target.push_back(arr[i]);
        count += 1 + min(left, right)*2;
    }
    
    return count;
}

int main() {
	
	vector<int> numbers{2, 1, 4, 3};
	
	cout<<minoperations(numbers);
	
	return 0;
}
