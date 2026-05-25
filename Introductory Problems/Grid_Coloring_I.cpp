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
bool is_valid(int n , int m, int i , int j){
    return i>=0 && i<n && j>=0 && j<m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        int n,m;
        cin>>n>>m;
        vector<string> grid(n);
        for(int i=0 ; i<n ; i++){
            cin>>grid[i];
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                set<char> not_allowed;
                not_allowed.insert(grid[i][j]);
                if(is_valid(n,m,i-1,j)){
                    not_allowed.insert(grid[i-1][j]);
                }
                if(is_valid(n,m,i,j-1)) {
                    not_allowed.insert(grid[i][j-1]);
                }
                bool filled = false;
                for(int k=0;k<4;k++){
                    char ch = 'A'+k;
                    if(not_allowed.find(ch)==not_allowed.end()){
                        grid[i][j] = ch;
                        filled = true;
                        break;
                    }
                }
                if(!filled){
                    cout<<"IMPOSSIBLE"<<endl;
                    return 0;
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        return 0;
}