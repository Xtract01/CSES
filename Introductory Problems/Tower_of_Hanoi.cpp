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
void TH(int discs , int start , int end , int aux){
    if(discs==1){
        cout<<start<<" "<<end<<endl;
        return;
    }
    TH(discs-1,start,aux,end);
    cout<<start<<" "<<end<<endl;
    TH(discs-1,aux,end,start);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    TH(n,1,3,2);
}