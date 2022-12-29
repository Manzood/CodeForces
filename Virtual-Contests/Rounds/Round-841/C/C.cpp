#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int tot = 0;
    int leftmost = 0;
    while ((1LL << leftmost) <= n) leftmost++;
    if ((1LL << leftmost) & n) leftmost++;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        tot ^= a[i];
    }
    vector<int> squares;
    squares.push_back(0);
    for (int i = 1; i * i <= (1LL << leftmost); i++) {
        squares.push_back(i * i);
    }
    int ans = (n * (n + 1)) / 2;
    vector<int> left((1LL << (leftmost + 1)) + 1, 0);
    int cur = tot;
    left[0]++;
    int l = 0;
    for (int i = 0; i < n; i++) {
        cur ^= a[i];
        for (auto x : squares) {
            ans -= left[tot ^ x ^ cur];
        }
        l ^= a[i];
        left[l]++;
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
