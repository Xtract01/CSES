#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, tar;
    cin >> n >> tar;

    vector<pair<ll,ll>> arr;

    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        arr.push_back({x,i+1});
    }

    sort(arr.begin(),arr.end());

    for(ll i=0;i<n;i++){
        if(i>0 && arr[i].first==arr[i-1].first)
            continue;
        for(ll j=i+1;j<n;j++){
            if(j!=i+1 && arr[j].first==arr[j-1].first)
                continue;

            ll k=j+1,l=n-1;
            while(k<l){
                ll sum = arr[i].first
                       + arr[j].first
                       + arr[k].first
                       + arr[l].first;

                if(sum==tar){
                    cout << arr[i].second << " "
                         << arr[j].second << " "
                         << arr[k].second << " "
                         << arr[l].second;

                    return 0;
                }

                else if(sum<tar)
                    k++;

                else
                    l--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}