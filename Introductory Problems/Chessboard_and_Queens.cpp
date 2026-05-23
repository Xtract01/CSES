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

ll res = 0;
bool isValid(vector<string>&grid , int row , int col){
    if(grid[row][col]=='*') return false;
    for(int i = row-1 ; i>=0 ;i--){
        if(grid[i][col]=='Q' ) return false;
    }
    for(int i = row-1 , j = col-1; i>=0 && j>=0 ;i--,j--){
        if(grid[i][j]=='Q') return false;
    }
    for(int i = row-1 , j = col+1; i>=0 && j<8 ;i--,j++){
        if(grid[i][j]=='Q' ) return false;
    }
    return true;
}
void solve (vector<string>&grid , int row){
    if(row>=8){
        res++;
        return;
    }
    for(int col = 0; col<8 ; col++){
        if(isValid(grid,row,col)){
            grid[row][col] = 'Q';
            solve(grid,row+1);
            grid[row][col] = '.';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    res = 0;
    vector<string> grid(8);
    for (int i = 0; i < 8; i++) {
        cin >> grid[i];
    }
    solve(grid,0);
    cout<<res<<endl;
    return 0;
}