#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    int val = c + a - 2 * b;
    bool possible = false;
    if (val < 0) {
        // either increase c or a
        if (val % c == 0 || val % a == 0) {
            possible = true;
        }
    } else if (val > 0) {
        if (val % (2 * b) == 0) {
            possible = true;
        }
    } else {
        possible = true;
    }
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
