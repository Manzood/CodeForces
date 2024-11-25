#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

vector<int> g;
void precompute() {
    g = {0, 0, 0, 0};
    for (int i = 4; i < 100001; i++) {
        int f = 0;
        int val = 1;
        while (val * 2 <= i) {
            f++;
            val *= 2;
        }
        int cnt = 0;
        val = 1;
        while (val * f <= i) {
            cnt++;
            val *= f;
        }
        g.push_back(cnt);
    }
}

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += g[i];
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
