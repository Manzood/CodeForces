#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MAX_N = (int)1e8 + 2;

vector<int> ans(MAX_N, 0);

void precompute() {
    for (int i = 1; i < MAX_N; i++) {
        ans[i]++;
        ans[i] += ans[i - 1];
        if (i % 3 == 0) {
            ans[i]++;
            ans[i]++;
        }
        if (i % 2 == 0) {
            ans[i]++;
            ans[i]++;
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    printf("%lld\n", ans[n]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
