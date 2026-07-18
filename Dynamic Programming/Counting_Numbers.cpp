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
ll dp[20][11][2][2];
vector<int> digits;
ll dfs(int pos , int prevDigit , int tight , int leadingZero){
    if(pos==(int)digits.size()) return 1;
       ll &res = dp[pos][prevDigit][tight][leadingZero];
    if(res!=-1) return res;
    res = 0;
    int limit = tight ? digits[pos] : 9;
    for(int d= 0 ; d<=limit ; d++){
        if(!leadingZero){
            if(d==prevDigit) continue;
        }
        int nextTight = tight && (d==limit);
        int nextLeadingZero = (leadingZero && d==0);
        int nextPrev;
        if(nextLeadingZero) nextPrev = 10;
        else nextPrev = d;
        res+=dfs(pos+1,nextPrev,nextTight,nextLeadingZero);

    }
    return res;
}
ll countUpto(ll x){
    if(x<0) return 0;
    digits.clear();
    if(x==0) digits.push_back(0);
    while(x>0) {digits.push_back(x%10);x/=10;}
    reverse(digits.begin(),digits.end());
     memset(dp, -1, sizeof(dp));
    return dfs(0,10,1,1);
    
}
void solve() {
    // Write your solution for one test case here
   
    ll a , b;
    cin>>a>>b;
    cout << countUpto(b) - countUpto(a-1) << '\n';
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