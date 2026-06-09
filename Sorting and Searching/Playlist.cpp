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
    for(ll i=0 ;i<n ; i++){
        cin>>vec[i];
    }
    ll i=0 , j=0;
    ll maxLen = 0;
    map<ll,ll>mp;
    while(j<n){
        if(mp.find(vec[j])!=mp.end()){
            if(mp[vec[j]]>=i) {
                i = mp[vec[j]] +1;
            }
        }
        maxLen = max(j-i+1,maxLen);
        mp[vec[j]] = j;
        j++;
    }
    cout<<maxLen<<endl;
   
}