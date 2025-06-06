#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = stoi(s);

    bool found = false;
    int x = -1, y = -1;
    for (int a = 0; a <= 100 && !found; a++) {
        for (int b = 0; (a + b) * (a + b) <= n; b++) {
            if ((a + b) * (a + b) == n) {
                found = true;
                x = a, y = b;
                break;
            }
        }
    }

    if (found) {
        printf("%lld %lld\n", x, y);
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
