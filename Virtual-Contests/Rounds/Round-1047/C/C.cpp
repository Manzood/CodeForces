#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    if (a % 2 == 1 && b % 2 == 1) {
        printf("%lld\n", a * b + 1);
    } else if (a % 2 == 0 && b % 2 == 1) {
        printf("-1\n");
    } else if (a % 2 == 1 && b % 2 == 0) {
        if (b % 4 == 0) {
            printf("%lld\n", a * b / 2 + 2);
        } else {
            printf("-1\n");
        }
    } else {
        printf("%lld\n", a * b / 2 + 2);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
