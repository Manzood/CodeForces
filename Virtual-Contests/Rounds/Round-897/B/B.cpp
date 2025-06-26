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
    string s;
    cin >> s;
    int diff = 0;
    for (int i = 0; i < n / 2; i++) {
        diff += (s[i] != s[n - i - 1]);
        // if (test == 1) debug(i, s[i], s[n - i - 1], diff);
    }
    for (int i = 0; i <= n; i++) {
        if (i >= diff && ((i - diff) % 2 == 0 || (n & 1)) && i <= n - diff) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
