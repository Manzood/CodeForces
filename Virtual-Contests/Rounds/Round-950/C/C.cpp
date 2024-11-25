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
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    map<int, int> req, cnt;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (a[i] != b[i]) {
            req[b[i]]++;
        }
    }
    scanf("%lld", &m);
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &d[i]);
        cnt[d[i]]++;
    }
    bool found = false;
    for (auto x : b)
        if (x == d[m - 1]) found = true;
    bool ans = found;
    for (auto x : req) {
        if (x.second > cnt[x.first]) ans = false;
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
