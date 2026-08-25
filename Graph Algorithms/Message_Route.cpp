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
    int n , m;
    cin>>n>>m;
    vector<vector<int>>edges(n);
    vector<bool> vis(n,false);
    for(int i=0 ; i<m ; i++){
        int x,y;
        cin>>x>>y;
        edges[x-1].push_back(y-1);
        edges[y-1].push_back(x-1);
    }
    vector<int> route(n,-1);
    queue<int> q;
    route[0] = -1;
    vis[0] = true;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int &ngbr:edges[node]){
            if(!vis[ngbr]){
                vis[ngbr] = true;
                route[ngbr] = node;
                q.push(ngbr);
            }
        }
    }
    if(!vis[n-1]){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> path;
    int curr = n-1;
    while(curr != -1) {
        path.push_back(curr);
        curr = route[curr];
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    for(int i=0 ; i<path.size();i++){
        cout<<path[i]+1<<" ";
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