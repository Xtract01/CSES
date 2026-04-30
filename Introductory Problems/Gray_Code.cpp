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
vector<string> generate_gcd(int n){
    if(n==1) return {"0","1"};
    vector<string> gcodes_n_minus_1 = generate_gcd(n-1);
    vector<string> mirrored;
    for(int i= gcodes_n_minus_1.size()-1 ; i>=0 ;i--){
        mirrored.push_back(gcodes_n_minus_1[i]);
    }
    vector<string> new_codes;
    for(int i=0 ; i<gcodes_n_minus_1.size();i++){
        new_codes.push_back('0'+gcodes_n_minus_1[i]);
    }
    for(int i=0 ;i<mirrored.size();i++){
        new_codes.push_back('1'+mirrored[i]);
    }
    return new_codes;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    vector<string> gray_codes;
    gray_codes = generate_gcd(n);
    for(auto gc:gray_codes){
        cout<<gc<<endl;
    }

}