#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> arr;
vector<bool> visit;
vector<int> beauty;
int ans;

void dfs(int start, int t_rem, int cur)
{
    visit[start] = true;
    
    ans = max(ans, cur);
    
    for(auto x : arr[start])
    {
        if(!visit[x.first] && t_rem >= x.second*2)
        {
            dfs(x.first, t_rem - x.second*2, cur+beauty[x.first]);
        }
    }
    
    visit[start] = false;
    
}

int main() {
	
	int n, m, m_t;
	
	cin>>n;
	cin>>m;
	cin>>m_t;
	
	beauty.resize(n);
	vector<int> u(m), v(m), t(m);
	
	for(int i=0; i<n; i++) cin>>beauty[i];
	
	for(int i=0; i<m; i++) cin>>u[i];
	
	for(int i=0; i<m; i++) cin>>v[i];
	
	for(int i=0; i<m; i++) cin>>t[i];
	
	arr.resize(n);
	
	for(int i=0; i<m; i++) arr[u[i]].push_back({v[i], t[i]});
	visit.resize(n, false);
	ans = 0;
	dfs(0, m_t, beauty[0]);
	
	cout<<ans;
	
	return 0;
}
