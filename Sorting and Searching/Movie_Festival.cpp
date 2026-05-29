#include <bits/stdc++.h> // Includes almost all standard headers
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pair<int, int>>

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

    int t=1;
    // cin >> t;
    while (t--) {
        int n;
    cin >> n;

    vii times;
    for (int i = 0; i < n; i++) {
        int st, et;
        cin >> st >> et;
        
        times.push_back({et, st});
    }
    sort(times.begin(), times.end());

   
    int prev_et = times[0].first;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
       
        if (times[i].second >= prev_et) {
            cnt++;
            prev_et = times[i].first;
        }
    }
    cout << cnt << endl;
    }
    return 0;
}