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
    ll n , x;
    cin>>n>>x;
    vector<pair<ll,ll>> vec;
    for(ll i = 0 ;i<n ; i++){
        ll x ;
        cin>>x;
        vec.push_back({x,i+1});
    }
    sort(vec.begin(),vec.end());
    ll i = 0 , j = n-1;
    while(i<j){
        ll sum = vec[i].first + vec[j].first;
        if(sum == x) {
            cout<< vec[i].second<<" "<<vec[j].second;
            return 0;
        }
        else if(sum<x){
            i++;
        }
        else j--;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}