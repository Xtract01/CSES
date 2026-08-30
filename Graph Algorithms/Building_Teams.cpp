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

void solve() {
    // Write your solution for one test case here
    int n , m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0 ; i<m ; i++){
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vector<int> assignedSet(n,-1);
    queue<int> q;
    for (int start = 0; start < n; start++) {
        if (assignedSet[start] != -1)
            continue;

        assignedSet[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int ngbr : graph[node]) {
                if (assignedSet[ngbr] == assignedSet[node]) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
                if (assignedSet[ngbr] == -1) {
                    assignedSet[ngbr] =
                        (assignedSet[node] == 1 ? 2 : 1);
                    q.push(ngbr);
                }
            }
        }
    }
    for(int i=0 ; i<n ; i++) cout<<assignedSet[i]<<" ";
    cout<<endl;
    
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