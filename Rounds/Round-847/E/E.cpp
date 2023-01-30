#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x;
    scanf("%lld", &x);
    bool possible = true;
    if (x & 1) {
        possible = false;
    }
    int b = x;
    int a = 0;
    bool flag = false;
    for (int i = 1; i <= 30; i++) {
        if ((1LL << i) & b) {
            if (!flag) {
                a += (1LL << (i - 1));
            } else {
                possible = false;
            }
            flag = true;
        } else {
            flag = false;
        }
    }
    b += a;
    if (possible) {
        printf("%lld %lld\n", a, b);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
