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
ll solve_using_multiset(vector<ll>& nums, int n, int a, int b) {
    multiset<ll> wnd;
    vector<ll> psums(n + 1, 0);
    ll ans = -1e18;

    for (int i = 1; i <= n; i++) {
        psums[i] = psums[i - 1] + nums[i];
        if (i < a) continue;
        wnd.insert(psums[i - a]);
        if (i > b) {
            wnd.erase(wnd.find(psums[i - b - 1]));
        }
        ll mss_i = psums[i] - *begin(wnd);
        ans = max(mss_i, ans);
    }

    return ans;
}  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

     int n, a, b;
    cin >> n >> a >> b;

    vector<ll> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    ll ans = solve_using_multiset(nums, n, a, b);
    cout << ans << "\n";
}