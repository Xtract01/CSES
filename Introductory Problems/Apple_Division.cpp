#include <bits/stdc++.h> // Includes almost all standard headers
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
void solve(vector<ll> &vec, ll i, ll n, ll grp1, ll grp2, ll &res) {
    if(i == n) {
        res = min(res, abs(grp1 - grp2));
        return;
    }

    solve(vec, i + 1, n, grp1 + vec[i], grp2, res);
    solve(vec, i + 1, n, grp1, grp2 + vec[i], res);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> weights(n);
    for(ll i=0; i<n ; i++){
        cin>>weights[i];
    }
    ll ans = 1e18;
    solve(weights,0,n,0,0,ans);
    cout<<ans<<endl;
    return 0;
}
