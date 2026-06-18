#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define len(x) int((x).size())

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Interval {
    int start, end, original_index;

    Interval(int s, int e, int idx)
        : start(s), end(e), original_index(idx) {}
};

bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.start == b.start)
        return a.end > b.end;
    return a.start < b.start;
}

void solve() {
    int n;
    cin >> n;

    vector<Interval> intervals;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;

        intervals.emplace_back(s, e, i);
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<int> is_contained_by_another(n, 0);
    vector<int> contains_another(n, 0);

    ordered_set<pair<int, int>> ets;

    for (int i = 0; i < n; i++) {
        auto& cur = intervals[i];

        int lb = ets.order_of_key({cur.end, -1});

        is_contained_by_another[cur.original_index] =
            len(ets) - lb;

        ets.insert({cur.end, i});
    }

    ets.clear();

    for (int i = n - 1; i >= 0; i--) {
        auto& cur = intervals[i];

        int ub = ets.order_of_key({cur.end, INT_MAX});

        contains_another[cur.original_index] = ub;

        ets.insert({cur.end, i});
    }

    for (int i = 0; i < n; i++) {
        cout << contains_another[i];

        if (i < n - 1)
            cout << " ";
    }

    cout << '\n';

    for (int i = 0; i < n; i++) {
        cout << is_contained_by_another[i];

        if (i < n - 1)
            cout << " ";
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}