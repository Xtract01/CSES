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
bool isPossible(ll mid , ll k ,vector<ll> &arr){
    ll total = 0;
    for(ll i=0 ; i< arr.size(); i++){
        total+=mid/arr[i];
        if (total >= k)
            return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        ll n , k ;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i=0 ; i<n ;i++){
            cin>>arr[i];
        }
        ll lo=1 , hi = 1e18;
        ll ans = 0;
        while(lo<=hi){
            ll mid = lo+(hi-lo)/2;
            if(isPossible(mid,k,arr)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        cout<<ans<<endl;

    return 0;
}