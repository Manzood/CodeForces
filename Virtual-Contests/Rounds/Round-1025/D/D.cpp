#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, m, l;
    scanf("%lld%lld%lld", &n, &m, &l);
    vector<int> a(l);
    bool hasOdd = false;
    for (int i = 0; i < l; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1) hasOdd = true;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    bool same = true;
    vector<int> pref(l, 0);
    for (int i = 0; i < l; i++) {
        if (i == 0) {
            pref[i] = a[i];
        } else {
            if ((a[i] & 1) != (a[i - 1] & 1)) same = false;
            pref[i] = a[i] + pref[i - 1];
        }
    }

    vector<int> edist(n, INF), odist(n, INF);
    auto dijkstra = [&]() {
        set<pair<int, int>> even, odd;
        edist[0] = 0;
        for (int i = 1; i < n; i++) {
            even.insert({INF, i});
            odd.insert({INF, i});
        }
        even.insert({0, 0});
        odd.insert({INF, 0});

        while (!even.empty() || !odd.empty()) {
            pair<int, int> chosen;
            if (even.empty()) {
                chosen = *odd.begin();
                odd.erase(odd.begin());
            } else if (odd.empty()) {
                chosen = *even.begin();
                even.erase(even.begin());
            } else {
                pair<int, int> etop = *even.begin();
                pair<int, int> otop = *odd.begin();
                if (etop.first < otop.first) {
                    chosen = etop;
                    even.erase(even.begin());
                } else {
                    chosen = otop;
                    odd.erase(odd.begin());
                }
            }

            for (auto u : adj[chosen.second]) {
                int val = chosen.first + 1;
                if (val & 1) {
                    if (odist[u] > val) {
                        odd.erase({odist[u], u});
                        odist[u] = min(odist[u], val);
                        odd.insert({odist[u], u});
                    }
                } else {
                    if (edist[u] > val) {
                        even.erase({edist[u], u});
                        edist[u] = min(edist[u], val);
                        even.insert({edist[u], u});
                    }
                }
            }
        }
    };

    dijkstra();

    string ans = "1";
    for (int i = 1; i < n; i++) {
        bool found = false;

        int dist = edist[i];
        int ind = lower_bound(pref.begin(), pref.end(), dist) - pref.begin();
        if (ind < l) {
            int val = pref[ind];
            if ((val - dist) % 2 == 0) {
                found = true;
            } else {
                if (ind < l - 1 && (!same || hasOdd)) found = true;
            }
        }

        dist = odist[i];
        ind = lower_bound(pref.begin(), pref.end(), dist) - pref.begin();
        if (ind < l) {
            int val = pref[ind];
            if ((val - dist) % 2 == 0) {
                found = true;
            } else {
                if (ind < l - 1 && (!same || hasOdd)) found = true;
            }
        }

        if (found) {
            ans += '1';
        } else {
            ans += '0';
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
