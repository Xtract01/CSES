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
    ll n,k;
    cin>>n>>k;
    vector<pair<int,int>> intervals;
    for(ll i=0 ; i<n ;i++){
        ll start, end;
        cin>>start>>end;
        intervals.push_back({end,start});
    }
    sort(intervals.begin(),intervals.end());

    ll total = 1;
    multiset<ll> ets;
    ets.insert(intervals[0].first);

    for(ll i=1 ; i<n ; i++){
        ll curr_et = intervals[i].first;
        ll curr_st = intervals[i].second;
        auto it = ets.upper_bound(curr_st);
        if(it == ets.begin()){
            if(ets.size() < k){
                ets.insert(curr_et);
                total++;
            }
        }
        else{
            it--;
            ets.erase(it);
            ets.insert(curr_et);
            total++;
        }
    }
    cout<<total<<endl;
    return 0;
}