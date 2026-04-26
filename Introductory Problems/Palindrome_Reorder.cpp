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
        // Solve each test case here
        string s;
        cin>>s;
        int n = s.length();
        vector<int> freq(26, 0);
        for(char ch : s) freq[ch - 'A']++;
        int cnt = 0;
        vector<char> c(n);
        char mid;
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 != 0){
                cnt++;
                mid = char(i + 'A');
            }
        }

        if(cnt>1){
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
        
     int left = 0, right = n - 1;
        for(int i = 0; i < 26; i++){
            while(freq[i] >= 2){
                c[left++] = char(i + 'A');
                c[right--] = char(i + 'A');
                freq[i] -= 2;
            }
        }
        if(cnt == 1){
            c[n / 2] = mid;
        }
        for(char ch : c) cout << ch;
        cout << '\n';

    
    return 0;
}
