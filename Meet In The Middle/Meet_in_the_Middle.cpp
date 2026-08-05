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
    int n;
    ll x;
    cin>> n >> x;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    int n1 = n/2;
    int n2 = n-n1;
    vector<ll> sumsA(1LL<<n1);
    for(int mask = 0 ; mask<(1<<n1);mask++){
        ll s = 0;
        for(int i=0 ; i<n1 ; i++){
            if(mask & (1<<i)){
                s+=a[i];
            }
        }
        sumsA[mask] = s;
    }
    vector<ll> sumsB(1LL<<n2);
    for(int mask = 0 ; mask<(1<<n2);mask++){
        ll s = 0;
        for(int i=0 ; i<n2 ; i++){
            if(mask & (1<<i)){
                s+=a[n1+i];
            }
        }
        sumsB[mask] = s;
    }
    sort(sumsA.begin(),sumsA.end());
    sort(sumsB.begin(),sumsB.end());

    ll cnt = 0;
    for(ll s:sumsA){
        ll need = x - s;
        auto lo = lower_bound(sumsB.begin(),sumsB.end(),need);
        auto hi = upper_bound(sumsB.begin(),sumsB.end(),need);
        cnt+=hi-lo;
    }
    cout<<cnt<<endl;
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