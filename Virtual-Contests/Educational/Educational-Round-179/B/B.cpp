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

    vector<int> fib(10);
    fib[0] = 1, fib[1] = 2;
    for (int i = 2; i < 10; i++) fib[i] = fib[i - 1] + fib[i - 2];

    vector<vector<int>> a(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
    }

    int last = fib[n - 1];
    int sec = fib[n - 2];

    string ans;
    for (int i = 0; i < m; i++) {
        int val = last + sec;
        bool found = false;

        for (int j = 0; j < 3 && !found; j++) {
            if (a[i][j] >= val) {
                found = true;
                for (int k = 0; k < 3; k++) {
                    if (a[i][k] < last) found = false;
                }
            }
        }

        if (found) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
