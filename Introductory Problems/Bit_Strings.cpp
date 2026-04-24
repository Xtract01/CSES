#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp) {
    if(exp==0) return 1;
    ll half = mod_exp(base,exp/2);
    ll result = half*half%MOD;
    if(exp%2==1) result = result*base%MOD;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    cout << mod_exp(2, n) << '\n';
    return 0;
}