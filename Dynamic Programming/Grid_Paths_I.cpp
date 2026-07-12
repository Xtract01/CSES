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
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ;j<n ; j++) cin>>grid[i][j];
    }
    if (grid[0][0] == '.') dp[0][0] = 1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(grid[i][j]=='*') continue;
            if (i == 0 && j == 0) continue;
            ll up = 0 , left = 0;
            if (i>0) up = dp[i-1][j];
            if (j>0) left = dp[i][j-1];
            dp[i][j]=(up+left)%MOD;
        }
    }
    cout<<dp[n-1][n-1]%MOD<<endl;

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