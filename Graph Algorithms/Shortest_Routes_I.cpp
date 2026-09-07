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

void solve() {
    // Write your solution for one test case here
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<pair<int,ll>>> adj;
    for(int i=0 ; i<m ; i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    vector<ll> dis(n+1,LLONG_MAX);
    dis[1] = 0;
    que.push({0,1});
    while(!que.empty()){
        pair<ll,int> p = que.top();
        que.pop();
        ll currDist = p.first;
        int node = p.second;
        if(currDist >dis[node]) continue;

        for(pair<int,ll> ngbr: adj[node]){
            int nbr = ngbr.first;
            ll weight = ngbr.second;
            if(dis[node] + weight < dis[nbr]){
                dis[nbr] = dis[node] + weight;
                que.push({dis[nbr],nbr});
            }
        }
    }
    for(int i=1 ; i<=n ; i++) cout<<dis[i]<<" ";
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