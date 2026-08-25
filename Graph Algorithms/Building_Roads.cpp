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
void dfs(int node , vector<vector<int>>&roads,vector<bool> &vis){
    vis[node] = true;
    for(int &ngbr: roads[node]){
        if(!vis[ngbr]){
            dfs(ngbr,roads,vis);
        }
    }
}
void solve() {
    // Write your solution for one test case here
    int n , m;
    cin>>n>>m;
    vector<vector<int>> roads(n);
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin>>x>>y;
        roads[x-1].push_back(y-1);
        roads[y-1].push_back(x-1);
    }
    int cnt = 0;
    vector<bool> vis(n,false);
    vector<int> res;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            cnt++;
            res.push_back(i+1);
            dfs(i,roads,vis);
        }
    }
    cout<<cnt-1<<endl;
    for(int i = 1; i < res.size(); i++) {
        cout << res[i - 1] << " " << res[i] << endl;
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