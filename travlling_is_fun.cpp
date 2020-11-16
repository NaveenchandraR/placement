#include <bits/stdc++.h>
using namespace std;

vector<int> parent,siz;

// used disjoint set union to find if originCities[i] is connected or not to destinationCities[i]
int find_set(int x)
{
    if(parent[x]==x) return x;
    
    return find_set(parent[parent[x]]);
}

void union_find(int i, int j)
{
    int a = find_set(i);
    int b = find_set(j);
    
    if(a!=b)
    {
        if(siz[a]<siz[b])swap(a,b);
        
        siz[a]+=siz[b];
        parent[b] = a;
    }
    return;
}

vector <int> connectedCities(int n, int g, vector <int> originCities, vector <int> destinationCities) {
    
    
    parent.clear();
    for(int i=0;i<=n;i++)
    {
        parent.push_back(i);
    }
    siz.assign(n+1,1);
    
    for(int i=g+1;i<=n;i++)
    {
        for(int j =2*i;j<=n;j+=i)
        {
            union_find(j,i);
        }
    }
    
    
    vector<int> ret;
    for(int i=0;i<originCities.size();i++)
    {
        if(find_set(destinationCities[i])==find_set(originCities[i])) ret.push_back(1);
        else ret.push_back(0);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    int g;
    cin >> g;
    int originCities_cnt;
    cin >> originCities_cnt;
    vector<int> originCities(originCities_cnt);
    for(int originCities_i = 0; originCities_i < originCities_cnt; originCities_i++){
        cin >> originCities[originCities_i];
    }
    int destinationCities_cnt;
    cin >> destinationCities_cnt;
    vector<int> destinationCities(destinationCities_cnt);
    for(int destinationCities_i = 0; destinationCities_i < destinationCities_cnt; destinationCities_i++){
        cin >> destinationCities[destinationCities_i];
    }
    vector <int> res = connectedCities(n, g, originCities, destinationCities);
    for (ssize_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
