#include <bits/stdc++.h> 
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
        // Solve each test case her
        ll n;
        cin>>n;
        multiset<ll> tower_heads;
        for(ll i=0 ; i<n ; i++){
            ll h;
            cin>>h;

            auto it = tower_heads.upper_bound(h);
            if(it == tower_heads.end()){
                tower_heads.insert(h);
            }
            else {
                tower_heads.erase(it);
                tower_heads.insert(h);
            }
        }
        cout<<tower_heads.size()<<endl;
    return 0;
} 