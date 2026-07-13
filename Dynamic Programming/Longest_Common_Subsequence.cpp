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
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<m ; i++) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    vector<int> res;
    int i=n , j = m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            res.push_back(a[i-1]);
            i = i-1;
            j = j-1;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i = i-1;
            else j = j-1;
        }
    }
    cout<<dp[n][m]<<endl;
    for(int i=res.size()-1 ; i>=0 ;i-- ){
        cout<<res[i]<<" ";
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