#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string a, b;
    cin >> a >> b;

    int n = (int)a.size();
    bool lower = true, higher = true;
    int ans = 0;
    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (lower && higher) {
            if (a[i] == b[i]) {
                ans += 2;
            } else if (a[i] < b[i] - 1) {
                break;
            } else {
                ind = i + 1;
                ans++;
                break;
            }
        }
    }

    int f1 = 0;
    if (ind > -1) {
        // try lower from ind
        for (int i = ind; i < n; i++) {
            if (a[i] == '9') {
                f1 += 1 + (b[i] == '9');
            } else if (a[i] == '8') {
                f1 += (b[i] == '9');
                break;
            } else {
                break;
            }
        }
    }

    int f2 = 0;
    if (ind > -1) {
        for (int i = ind; i < n; i++) {
            if (b[i] == '0') {
                f2 += 1 + (a[i] == '0');
            } else if (b[i] == '1') {
                f2 += (a[i] == '0');
                break;
            } else {
                break;
            }
        }
    }

    ans += min(f1, f2);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
