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
    vector<vector<ll>> dir = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
    vector<vector<int>> board(n,vector<int>(n,-1));
    board[0][0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k = 0; k<8 ; k++){
            int new_i = i+dir[k][0];
            int new_j = j+dir[k][1];
            if(new_i>=0 && new_j>=0 && new_i<n && new_j<n && board[new_i][new_j]==-1){
                board[new_i][new_j] = board[i][j]+1;
                q.push({new_i,new_j});
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}