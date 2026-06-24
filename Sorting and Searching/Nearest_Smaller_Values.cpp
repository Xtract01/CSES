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
    stack<pair<ll,ll>> st;
    cout<<0<<" ";
    st.push({a[0],1});
    for(ll i=1 ; i<n ; i++){
        while(!st.empty()&&st.top().first>=a[i]) st.pop();
        if(st.empty())cout<<0<<" ";
        else cout<<st.top().second<<" ";
        st.push({a[i],i+1});
    }
    return 0;
}