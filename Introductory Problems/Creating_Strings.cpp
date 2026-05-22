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
void solve(string &s, int n, string &curr,
           vector<int> &flag, set<string> &res) {

    if (curr.size() == n) {
        res.insert(curr);
        return;
    }

    for (int i = 0; i < n; i++) {

        if (flag[i] == 1)
            continue;

        flag[i] = 1;
        curr.push_back(s[i]);

        solve(s, n, curr, flag, res);

        curr.pop_back();
        flag[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n = s.length();
    vector<int> flag(n, 0);
    set<string> res;
    string curr = "";
    solve(s, n, curr, flag, res);
    cout<<res.size()<<endl;
    for(auto &x : res) cout<<x<<"\n";
    return 0;
}