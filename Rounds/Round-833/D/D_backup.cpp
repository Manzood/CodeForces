#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, d;
    scanf("%lld%lld%lld", &a, &b, &d);
    vector<vector<int>> m(2, vector<int>(60, 0));
    for (int i = 0; i < 30; i++) {
        int val = 1LL << i;
        m[0][i] = ((a | val) % d) % d;
        m[1][i] = ((b | val) % d) % d;
    }
    debug(m);
    int ans = -1;
    vector<set<int>> s(2);
    vector<map<int, int>> mp(2);
    s[0].insert(m[0][0]);
    s[1].insert(m[1][0]);
    mp[0][0] = 0;
    mp[1][0] = 0;
    for (int i = 1; i < 30; i++) {
        for (auto x : s[0]) {
            int val = (x + m[0][i]) % d;
            s[0].insert(val);
            mp[0][val] = mp[0][x] | (1LL << i);
        }
        for (auto x : s[1]) {
            int val = (x + m[1][i]) % d;
            s[1].insert(val);
            mp[1][val] = mp[1][x] | (1LL << i);
        }
        if (s[0].count(0) && s[1].count(0)) {
            ans = mp[0][0];
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
