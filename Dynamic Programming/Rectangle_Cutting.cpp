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
    int a , b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
    for(int i=1 ; i<=a ; i++){
        for(int j=1 ; j<=b ; j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            for(int v=1 ; v<=i-1 ; v++){
                dp[i][j] = min(dp[i][j],dp[v][j]+dp[i-v][j]+1);
            }
            for(int h=1 ; h<=j-1 ; h++){
                dp[i][j] = min(dp[i][j],dp[i][h] + dp[i][j-h]+1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return;
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