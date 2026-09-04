#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const ll INF = LLONG_MAX;
const int INF_INT = INT_MAX;
const ll NEG_INF = LLONG_MIN;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

int cycleStart = -1 , cycleEnd = -1;
bool dfs(int node, int par ,vector<vector<int>> &edges, vector<bool> &vis , vector<int> &parent ){
    vis[node] = true;
    for(int ngbr:edges[node]){
        if(ngbr==par) continue;
        if(vis[ngbr]){
            cycleStart = ngbr;
            cycleEnd = node;
            return true;
        }
        else {
            parent[ngbr] = node;
            if(dfs(ngbr,node,edges,vis,parent)) return true;
        }
    }
    return false;
}
void solve() {
    // Write your solution for one test case here
    int n , m;
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> parent(n+1,-1);
    vector<bool> vis(n+1,false);
    for(int i=1 ; i<=n ; i++){
        if(!vis[i] && dfs(i,-1,edges,vis,parent)) break;
    }
    if(cycleStart == -1 ) cout<<"IMPOSSIBLE"<<endl;
    else {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        int curr = cycleEnd;
        while(curr != cycleStart){
            cycle.push_back(curr);
            curr = parent[curr];
        }
        cycle.push_back(cycleStart);
        reverse(cycle.begin(),cycle.end());

        cout<<cycle.size()<<endl;
        for(int node:cycle) cout<<node<<" ";
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}