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
    ll n,sum;
    cin>>n>>sum;
    vector<ll> a(n);
    for(ll i=0 ; i<n ; i++) cin>>a[i];
    vector<ll> ahead(sum+1,0),curr(sum+1,0);
    ahead[0] = 1;
    curr[0] = 1;
    for(ll i=n-1;i>=0;i--){
        for(ll x=1 ; x<=sum ; x++){
            ll skip = ahead[x];
            ll pick = 0;
            if(a[i]<=x) pick = curr[x-a[i]];
           curr[x] = (skip+pick)%MOD;
        }
        ahead=curr;
    }
    cout<<ahead[sum]<<endl;
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