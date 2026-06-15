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
void josephes(vector<ll> &a , ll n){
    if(n==1){
        cout<<a[0]<<endl;
        return;
    }
    for(ll i=1 ; i<n; i+=2){
        cout<<a[i]<<" ";
    }
    vector<ll> next;
    if(n%2==0){
        for(ll i=0 ; i<n ; i+=2){
            next.push_back(a[i]);
        }
    }
    else{
        next.push_back(a[n-1]);
        for(ll i=0 ; i<n-1 ; i+=2){
            next.push_back(a[i]);
        }
    }
    josephes(next,next.size());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        a[i]=i+1;
    josephes(a,n);
    return 0;
}