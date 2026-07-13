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
bool valid(int x, int m){
    return x >= 1 && x <= m;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=1;i<=m ; i++){
        if(a[0]==i || a[0]==0) dp[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(a[i-1]!=0 && a[i-1]!=k){
                dp[i][k] = 0;
                continue;
            }
            for(int prev = k-1 ;prev<=k+1 ; prev++){
                if(!valid(prev,m)) continue;
                dp[i][k] = (dp[i][k] + dp[i-1][prev])%MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n][i]) % MOD;
    }
    
    
    cout << ans << endl;
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