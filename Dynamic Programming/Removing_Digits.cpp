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

vector<int> getDigits(int n){
    vector<int> res;
    while(n>0){
        res.push_back(n%10);
        n/=10;
    }
    return res;
}
void solve() {
    // Write your solution for one test case here
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0] = 0;
    for(int i=1 ; i<=9; i++) dp[i] = 1;
    for(int i=10 ; i<=n ; i++){
        vector<int> digits = getDigits(i);
        int res = INT_MAX;
        for(int j=0 ; j<digits.size();j++){
            if (digits[j] == 0) continue;
            res = min(res,1+dp[i-digits[j]]);
        }
        dp[i] = res;
    }
    cout<<dp[n]<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}