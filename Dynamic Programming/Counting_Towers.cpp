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

vector<vector<int>> dp(1000002, vector<int>(2));

void precompute() {
    dp[1][0] = dp[1][1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        dp[i][0] = (2LL * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + 4LL * dp[i-1][1]) % MOD;
    }
}


void solve() {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t ;

    while (t--) {
        solve();
    }

    return 0;
}