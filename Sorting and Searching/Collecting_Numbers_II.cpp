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
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> pos;
    pos[0] = 0;
    pos[n + 1] = n + 1;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rounds++;
    }


    while (m--) {
        int i, j;
        cin >> i >> j;
        if (i > j) swap(i, j);

        int x = arr[i];
        int y = arr[j];

        if (pos[x + 1] > i && pos[x + 1] < j) rounds++;
        if (pos[x - 1] > i && pos[x - 1] < j) rounds--;
        if (pos[y + 1] > i && pos[y + 1] < j) rounds--;
        if (pos[y - 1] > i && pos[y - 1] < j) rounds++;
        if (x == (y + 1)) rounds--;  // {...,2,...,1,...}
        if (x == (y - 1)) rounds++;  // {...,1,...,2,...}

        cout << rounds << endl;
        swap(arr[i], arr[j]);
        pos[x] = j;
        pos[y] = i;
    }
     
    return 0;

}