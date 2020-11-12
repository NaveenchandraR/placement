class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        
        int size = s.length();
        vector<vector<int>> arr(size+1, vector<int>(26, 0));
        
        for(int i=0; i<size; i++)
        {
            arr[i+1].assign(arr[i].begin(), arr[i].end());
            arr[i+1][s[i]-'a']++;
        }
        
        int qlen = queries.size();
        vector<bool> sol;
        for(int i=0; i<qlen; i++)
        {
            int count = 0;
            for(int j=0; j<26; j++)
                count += (arr[queries[i][1]+1][j] - arr[queries[i][0]][j]) % 2;
            
        sol.push_back(queries[i][2] >= count/2);
        }
        return sol;
    }
};
