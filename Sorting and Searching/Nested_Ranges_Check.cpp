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

    int n;
    cin >> n;
    vector<tuple<ll,ll,int>> vec;
    for(int i=0;i<n;i++){
        ll l,r;
        cin >> l >> r;
        vec.push_back({l,r,i});
    }
    sort(vec.begin(),vec.end(),[](auto a, auto b){
        if(get<0>(a) != get<0>(b)) return get<0>(a)<get<0>(b);
        return get<1>(a)>get<1>(b);
    });
    vector<int> isContained(n,0), isContaining(n,0);
    ll maxi = LLONG_MIN;
    for(int i=0 ; i<n; i++){
        ll r= get<1>(vec[i]);
        if(maxi>=r){
            isContained[get<2>(vec[i])] = 1;
        }
        maxi = max(maxi,r);
    }
    ll minRight = LLONG_MAX;

    for(int i=n-1;i>=0;i--){

        ll r = get<1>(vec[i]);

        if(minRight <= r)
            isContaining[get<2>(vec[i])] = 1;

        minRight = min(minRight,r);
    }
    for(int x : isContaining)
    cout << x << " ";

    cout << '\n';

    for(int x : isContained)
        cout << x << " ";

    cout << '\n';
    return 0;
}