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
    vector<pair<ll,ll>> arr(n);
    for(ll i=0 ; i<n ;i++){
        ll x ;
        cin>>x;
        arr[i] = {x,i+1};
    }
    sort(arr.begin(),arr.end());
    for(ll i=0 ; i<n ;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        ll j=i+1;
        ll k = n-1;
        while(j<k){
            ll sum = arr[i].first+arr[j].first+arr[k].first;
            if(sum<x){
                j++;
            }
            else if(sum>x){
                k--;
            }
            else {
                cout << arr[i].second << " " << arr[j].second << " " << arr[k].second << "\n";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}