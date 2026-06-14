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
    for(ll i=0 ; i<n ; i++){
        cin>>a[i];
    }
    ll l=0 , r = 0 , ans = 0;
    map<ll,ll>mp;
    while(r<n){
        mp[a[r]]++;
        while(mp.size()<r-l+1){
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }
        ans+=r-l+1;
        r++;
    }
    cout<<ans<<endl;
    return 0;
}