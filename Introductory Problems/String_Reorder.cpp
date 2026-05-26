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
    string s;
    cin>>s;
    vector<ll> charFreq(26,0);
    ll maxFreq = LLONG_MIN; 
    for(char ch:s){
        charFreq[ch-'A']++;
        maxFreq = max(charFreq[ch-'A'],maxFreq);
    }
    int n = s.length();
    if(maxFreq > (n + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
     
    string res = "";
    while(res.length()<n){
        bool found = false;
        for(int i=0 ; i<26 ; i++){
            if(charFreq[i] == 0)
                continue;
            if(!res.empty() && res.back() == char('A' + i))
                continue;
            charFreq[i]--;

            ll mx = *max_element(all(charFreq));

            int rem = n - res.length() - 1;
            if(mx <= (rem + 1) / 2) {

                res += char('A' + i);
                found = true;
                break;
            }
            charFreq[i]++;
        }
        if(!found) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout<<res<<endl;
    return 0;
}