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
    int n,x;
    cin>>n>>x;
    vector<int> prices(n),pages(n);
    for(int i=0 ; i<n ; i++) cin>>prices[i];
    for(int i=0 ; i<n ; i++) cin>>pages[i];
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for (int w = 0; w <= x; w++) {
        if (w >= prices[0])
            dp[0][w] = pages[0];
    }
    for(int i=1 ; i<n ; i++){
        for(int w=0 ; w<=x ; w++){
            int take = 0;
            if(w>=prices[i]) take = pages[i] + dp[i-1][w-prices[i]];
            int notTake = dp[i-1][w];
            dp[i][w]=max(take,notTake);
        }
    }
    cout<<dp[n-1][x]<<endl;
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