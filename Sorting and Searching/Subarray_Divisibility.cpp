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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0 ; i<n ;i++) cin>>a[i];
    map<ll,ll> psums;
    psums[0] = 1;
    ll curr_sum = 0;
    ll total = 0;
    for(ll i=0 ; i<n ; i++){
        curr_sum += a[i];
        int mod = (curr_sum%n - n)%n;
        total+=psums[mod];
        psums[mod]++;
    }
    cout<<total<<endl;
    return 0;
}