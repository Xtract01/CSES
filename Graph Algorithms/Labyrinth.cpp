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
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    // R, U, L, D
    vector<int> dr = {0, -1, 0, 1};
    vector<int> dc = {1, 0, -1, 0};
    vector<char> directions = {'R', 'U', 'L', 'D'};

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> previousDirection(n, vector<char>(m, 0));

    pii start, end;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (grid[row][col] == 'A')
                start = {row, col};
            else if (grid[row][col] == 'B')
                end = {row, col};
        }
    }

    queue<pii> q;

    vis[start.first][start.second] = true;
    q.push(start);

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int new_r = row + dr[d];
            int new_c = col + dc[d];

            if (new_r >= 0 && new_r < n &&
                new_c >= 0 && new_c < m &&
                !vis[new_r][new_c] &&
                grid[new_r][new_c] != '#') {

                vis[new_r][new_c] = true;

                // Store the direction used to reach this cell
                previousDirection[new_r][new_c] = directions[d];

                q.push({new_r, new_c});
            }
        }
    }

    if (!vis[end.first][end.second]) {
        cout << "NO\n";
        return;
    }

    string path;
    pii current = end;

    // Reconstruct path from B -> A
    while (current != start) {
        char dir = previousDirection[current.first][current.second];
        path.push_back(dir);

        if (dir == 'R') {
            // We reached current by moving right,
            // so go left while reconstructing.
            current.second--;
        }
        else if (dir == 'L') {
            current.second++;
        }
        else if (dir == 'U') {
            current.first++;
        }
        else if (dir == 'D') {
            current.first--;
        }
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}