/**
 *    author:  tourist
 *    created: 06.11.2025 06:40:29
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> c(m);
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }
        multiset<int> s(a.begin(), a.end());
        vector<tuple<int, int, int>> all(m);
        for (int i = 0; i < m; i++) {
            all[i] = {int(c[i] == 0), b[i], i};
        }
        sort(all.begin(), all.end());
        int ans = 0;
        for (auto& [_, __, i] : all) {
            auto it = s.lower_bound(b[i]);
            if (it != s.end()) {
                ans += 1;
                int val = *it;
                s.erase(it);
                if (c[i] > 0) {
                    s.insert(max(val, c[i]));
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
