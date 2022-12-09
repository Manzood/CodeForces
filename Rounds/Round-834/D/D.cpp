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
    scanf("%lld%lld", &n, &m);
    int mult = 1;
    int x = n;

    while (x % 10 == 0) x /= 10;

    int zeroes = 0;
    while (x % 5 == 0 && mult * 2 <= m) {
        x /= 5;
        mult *= 2;
        zeroes++;
    }
    while (x % 2 == 0 && mult * 5 <= m) {
        x /= 2;
        mult *= 5;
        zeroes++;
    }
    while (mult * 10 <= m) {
        mult *= 10;
        zeroes++;
    }
    mult *= m / mult;

    printf("%lld\n", n * mult);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
