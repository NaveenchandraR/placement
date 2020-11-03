#include <bits/stdc++.h>
class Solution {
public:
    static bool comp(const vector<int>& a1, const vector<int>& a2)
    {
        return a1[1] < a2[1];
    }
    
    int find(vector<vector<int>>& jobs, int i)
    {
        int low = 0, high = i-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(jobs[mid][1] <= jobs[i][0])
            {
                if(jobs[mid+1][1] <= jobs[i][0])
                    low = mid+1;
                
                else
                    return mid;
            }
            else
                high = mid-1;
        }
        return -1;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int size = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0; i<size; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end(), comp);
        
        vector<int>table(size, 0);
        table[0] = jobs[0][2];
        
        for(int i=1; i<size; i++)
        {
            int incl = jobs[i][2];
            int l = find(jobs, i);
            
            if(l != -1) incl += table[l];
            
            table[i] = max(incl, table[i-1]);
        }
        return table[size-1];
    }
};