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
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }

    if ((int)even.size() > 1) {
        printf("%lld %lld\n", even[0], even[1]);
    } else {
        bool found = false;
        int x = 0, y = 0;
        for (int i = 0; i < n && !found; i++) {
            for (int j = i + 1; j < n && !found; j++) {
                if ((a[j] % a[i]) % 2 == 0) {
                    found = true;
                    x = a[i], y = a[j];
                }
            }
        }
        if (found) {
            printf("%lld %lld\n", x, y);
        } else {
            printf("-1\n");
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
