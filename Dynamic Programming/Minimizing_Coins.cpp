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

int helper(int sum,vector<int> &coins,vector<int> &dp){
    if(sum==0) return 0;
    if(dp[sum]!=-1) return dp[sum];
    int res = INT_MAX;
     for(int coin : coins) {
        if(sum >= coin) {
            int ans = helper(sum - coin, coins, dp);
            if(ans != INT_MAX)
                res = min(res, ans + 1);
        }
    }
    return dp[sum]=res;
}
void solve() {
    // Write your solution for one test case here
    int n , sum;
    cin>>n>>sum;
    vector<int> coins(n);
    vector<int> dp(sum+1,-1);
    for(int i=0 ; i<n ; i++) cin>>coins[i];
    int ans = helper(sum,coins,dp);

    if(ans == INT_MAX)
        cout << -1 << endl;
    else
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