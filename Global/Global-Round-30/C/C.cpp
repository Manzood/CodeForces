#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &c[i]);
    }

    vector<pair<int, int>> upgrades;
    vector<int> others;
    for (int i = 0; i < m; i++) {
        if (c[i] == 0) {
            others.push_back(b[i]);
        } else {
            upgrades.push_back({b[i], c[i]});
        }
    }

    int cnt = 0;
    sort(a.begin(), a.end());
    sort(upgrades.begin(), upgrades.end());
    sort(others.begin(), others.end());

    multiset<int> available;
    // debug(others);
    int ptr = 0;
    for (int x = 0; x < n; x++) {
        if (cnt >= (int)others.size()) break;
        if (a[x] >= others[cnt]) {
            cnt++;
        } else {
            int best = a[x];
            if (!available.empty()) best = max(best, *available.rbegin());
            while (ptr < (int)upgrades.size() && upgrades[ptr].first <= best) {
                available.insert(upgrades[ptr++].second);
                best = max(best, *available.rbegin());
            }
            debug(x);
            for (auto tmp : available) {
                debug(tmp);
            }
            while (!available.empty() && *available.begin() < others[cnt]) {
                available.erase(available.begin());
            }
            if (!available.empty()) {
                available.erase(available.begin());
                cnt++;
            }
        }
    }

    for (int i = 0; i < (int)upgrades.size(); i++) {
        if (a[n - 1] >= upgrades[i].first) {
            cnt++;
            a[n - 1] = max(a[n - 1], upgrades[i].second);
        }
    }

    assert(cnt <= m);

    printf("%lld\n", cnt);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
