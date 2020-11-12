#include <bits/stdc++.h>

class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    
    int latest(vector<vector<int>>& jobs, int i)
    {
        int lo = 0, hi = i - 1; 
  
        // Perform binary Search iteratively 
        while (lo <= hi) 
        { 
            int mid = (lo + hi) / 2; 
            if (jobs[mid][1] <= jobs[i][0]) 
            { 
                if (jobs[mid + 1][1] <= jobs[i][0]) 
                    lo = mid + 1; 
                else
                    return mid; 
            } 
            else
                hi = mid - 1; 
        } 

        return -1; 
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        
        int size = profit.size();
        
        vector<vector<int>> jobs;
        
        for(int i=0; i<size; i++) jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end(), compare);
        
        vector<int> table(size, 0);
        table[0] = jobs[0][2];
        
        for (int i=1; i<size; i++) 
        { 
            // Find profit including the current job 
            int inclProf = jobs[i][2]; 
            int l = latest(jobs, i); 
            if (l != -1) 
                inclProf += table[l]; 

            // Store maximum of including and excluding 
            table[i] = max(inclProf, table[i-1]); 
        } 
        
        return table[size-1];
        
    }
};
