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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0 ; i<n ; i++) cin>>a[i];
    ll i=0 , j=0 , ans = 0;
    unordered_map<ll,ll> mp;
    while(j<n){
        mp[a[j]]++;
        while(mp.size()>k){
            mp[a[i]]--;
            if(mp[a[i]]==0) mp.erase(a[i]);
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    cout<<ans<<endl;

    return 0;
}