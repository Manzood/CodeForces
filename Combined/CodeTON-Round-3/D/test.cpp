#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

void solve([[maybe_unused]] int test) {
    int o = (int)1e9;
    int val = o / 30 - o / 60;
    val *= (o / 30) * 8 + 2;
    int x = (o / 30) * 8 + 2;
    debug(x);
    val %= mod;
    val *= o;
    val %= mod;
    debug(val);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
