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
    vector<ll> vec(n);
    for(ll i = 0 ; i<n ; i++) cin>> vec[i];
    ll currSum = vec[0];
    ll maxSum = vec[0];
    for(ll i = 1 ; i<n ; i++){
        currSum  = max(vec[i],currSum+vec[i]);
        maxSum = max(maxSum , currSum);
    }
    cout<<maxSum<<endl;
    return 0;
}