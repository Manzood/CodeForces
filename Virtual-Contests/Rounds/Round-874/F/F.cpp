#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> b(n), a;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        mp[b[i]]++;
    }
    for (auto x : mp) a.push_back(x.first);
    int val = 1, ans = 0;
    for (int i = 0; i < m - 1 && i < (int)a.size(); i++)
        (val *= mp[a[i]]) %= MOD;
    for (int i = m - 1; i < (int)a.size(); i++) {
        (val *= mp[a[i]]) %= MOD;
        if (a[i - m + 1] == a[i] - m + 1) {
            (ans += val) %= MOD;
        }
        (val *= inv(mp[a[i - m + 1]], MOD)) %= MOD;
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
