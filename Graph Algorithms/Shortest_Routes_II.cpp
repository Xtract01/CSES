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
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n,vector<ll>(n,LLONG_MAX));
    for(int i=0 ; i<n ; i++){
        dist[i][i] = 0;
    }
    for(int i=0 ; i<m ; i++){
        int u,v;
        ll wt;
        cin>>u>>v>>wt;
        u--;v--;
        dist[u][v] = min(dist[u][v],wt);
        dist[v][u] = min(dist[v][u],wt);
    }
    for(int k=0;k<n;k++){
        for(int i=0 ; i<n;i++){
            for(int j=0 ; j<n ; j++){
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for(int i=0 ; i<q ; i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        cout<<(dist[x][y]==LLONG_MAX ? -1 : dist[x][y])<<endl;
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