#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = (int)1e5 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    vector<int> cnt(N, 0);
    map<int, int> mp;
    int ans = 1;

    for (int i = 0; i < n; i++) {
        if (mp.count(cnt[a[i]])) {
            int cur = --mp[cnt[a[i]]];
            if (cur == 0) {
                mp.erase(cnt[a[i]]);
            }
        }
        cnt[a[i]]++;
        mp[cnt[a[i]]]++;

        if ((int)mp.size() <= 2) {
            if ((int)mp.size() == 1) {
                auto f = *mp.begin();
                if (f.first == 1 || f.second == 1) ans = i + 1;
            } else {
                auto f = *mp.begin();
                auto s = *mp.rbegin();

                if ((f.second == 1 && f.first == s.first + 1) ||
                    (s.second == 1 && s.first == f.first + 1) ||
                    (s.first == 1 && s.second == 1) ||
                    (f.first == 1 && f.second == 1)) {
                    ans = max(ans, i + 1);
                }
            }
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
