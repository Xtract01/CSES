#include <bits/stdc++.h>
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
vector<char> DIR = {'U','D','R','L'};
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,1,-1};
void solve() {
    // Write your solution for one test case here
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i = 0 ; i<n ; i++) cin>>grid[i];
    vector<vector<int>> monster_time(n,vector<int>(m,INT_MAX));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<char>> parent(n,vector<char>(m));

    queue<pii> q;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 'M'){
                q.push({i,j});
                monster_time[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d =0 ; d<4 ; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && monster_time[nx][ny]>monster_time[x][y]+1){
                monster_time[nx][ny] = monster_time[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    pii start,exit = {-1,-1};
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) {
            if(grid[i][j]=='A') start = {i,j};
        }
    }
    q.push(start);
    vis[start.first][start.second] = true;
    vector<vector<int>> dist(n,vector<int>(m,0));

    bool escaped = false;
    while(!q.empty() && !escaped){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==0 || x==n-1 || y==0 || y==m-1) {
            exit = {x,y};
            escaped = true;
            break;
        }

        for(int d=0 ; d<4 ; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && !vis[nx][ny] && dist[x][y] + 1 < monster_time[nx][ny]){
                vis[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = DIR[d];
                q.push({nx,ny});
            }
        }
    }
    if(!escaped){
        cout<<"NO"<<endl;
        return;
    }

    string path;
    pii curr = exit;
    while(curr != start){
        char dir = parent[curr.first][curr.second];
        path.push_back(dir);

        int idx = find(DIR.begin(),DIR.end(),dir) - DIR.begin();
        curr.first -= dx[idx];
        curr.second -= dy[idx];
    }
    reverse(path.begin(),path.end());

    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
    return;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

     return 0;
}