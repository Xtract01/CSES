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

   
    int x, n;
    cin >> x >> n;

    multiset<int> plens;
    set<int> pos;
    pos.insert(0);
    pos.insert(x);

    plens.insert(x);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        auto right = pos.upper_bound(p);
        auto left = right;
        left--;
        int l = *left, r = *right;

        
        plens.erase(plens.find(r - l));  
        plens.insert(p - l);
        plens.insert(r - p);


        cout << *plens.rbegin() << " ";

       
        pos.insert(p);
    }
    cout << endl;
    return 0;
}