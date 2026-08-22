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

vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
int N,M;
void dfs(int row,int col , vector<vector<char>> &v ,vector<vector<bool>> &vis){
    vis[row][col] = true;
    for(vector<int> &d : dir){
        int new_r = row + d[0];
        int new_c = col + d[1];
        if(new_r>=0 && new_r<N && new_c>=0 && new_c<M && v[new_r][new_c]!='#'&& !vis[new_r][new_c]){
            dfs(new_r,new_c,v,vis);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    N=n , M=m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ;j<m ; j++) cin>>v[i][j];
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int res = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ;j<m ; j++){
            if(!visited[i][j] && v[i][j]=='.'){
                res++;
                dfs(i,j,v,visited);
            }
        }
    }
    cout<<res<<endl;
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