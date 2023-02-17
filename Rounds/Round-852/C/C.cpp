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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int start = 0, end = n - 1;
    int mi = 1, mx = n;
    bool found = false;
    int f = -1, s = -1;
    while (start <= end) {
        if (a[start] == mi) {
            mi++;
            start++;
        } else if (a[start] == mx) {
            start++;
            mx--;
        } else if (a[end] == mi) {
            end--;
            mi++;
        } else if (a[end] == mx) {
            end--;
            mx--;
        } else {
            found = true;
            f = start + 1;
            s = end + 1;
            break;
        }
    }
    if (found) {
        printf("%lld %lld\n", f, s);
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
