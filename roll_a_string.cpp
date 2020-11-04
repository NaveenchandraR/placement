#include <bits/stdc++.h>
string findRollOut(string s, long long arr[], int n)
	{
	    long long len = s.length();
	    vector<long long> temp(len, 0);
	    
	    for(int i=0; i<n; i++) temp[arr[i]-1]++;
	    
	    int ctr = 0;
	    string ret = "";
	    
	    for(long long i=len-1; i>=0; i--)
	    {
	        ctr += temp[i];
	        ret += ('a' + (s[i]-'a' + ctr)%26);
	    }
	    reverse(ret.begin(), ret.end());
	    return ret;
	}
