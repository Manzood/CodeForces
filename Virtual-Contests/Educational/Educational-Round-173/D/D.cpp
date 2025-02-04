#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r, g;
    scanf("%lld%lld%lld", &l, &r, &g);
    int left = l + ((l % g == 0) ? 0LL : g - (l % g));
    int right = g * (r / g);
    int low = left / g, high = right / g;
    pair<int, int> mx = {-1, -1};
    for (int i = low; i < low + 400 && i <= high; i++) {
        if (mx.second == high) break;
        for (int j = high; j > high - 400 && j >= i && j > mx.second; j--) {
            if (__gcd(i, j) == 1) {
                if (j - i > mx.second - mx.first || mx.first == -1) {
                    mx.second = j;
                    mx.first = i;
                }
            }
        }
    }
    if (mx.first != -1) {
        mx.first *= g;
        mx.second *= g;
    }
    printf("%lld %lld\n", mx.first, mx.second);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
