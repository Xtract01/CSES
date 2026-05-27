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
        // Solve each test case here
    ll n , m;
    cin>>n>>m;
    vector<ll> th(m);
    multiset<ll> tickets;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        tickets.insert(x);
    }
    for (ll i = 0; i < m; i++) {
        ll customer;
        cin >> customer;
        auto it = tickets.upper_bound(customer);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        }
        else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
    return 0;
} 