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
    int n ;
    cin>>n;
    for(int k = 1; k<=n ; k++){
        long long t_cell = k*k;
        if(k==1) cout<<0<<endl;
        else {
            long long total = (t_cell * (t_cell-1))/2;
            long long slabs = (k-2) * (k-1) * 4;
            cout<<total-slabs<<endl;
        }
    }
    return 0;
}
