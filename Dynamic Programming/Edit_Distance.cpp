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
    string s ,t;
    cin>>s;
    cin>>t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e7));
    for(int i=0 ; i<=n ; i++){
        dp[i][0] = i;
    }
    for(int j=0 ; j<=m ; j++) {
        dp[0][j] = j;
    }
    for(int i=1 ; i<=n  ;i++){
        for(int j=1 ; j<=m ; j++){
            char x = s[i-1];
            char y = t[j-1];
            if(x==y) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1] + 1;
            dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
        }
    }
    cout<<dp[n][m]<<endl;
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