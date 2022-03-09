#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, d;
    scanf("%lld%lld", &n, &d);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int smallest = a[0] - 1;
    int largest = a[0] - 1;
    int f = -1, s = 0;
    int midpoint = 1 + (a[0] - 1) / 2;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] - 1 < smallest) {
            smallest = a[i] - a[i-1] - 1;
            f = i - 1;
            s = i;
        }
        if (a[i] - a[i-1] - 1> largest) {
            midpoint = a[i-1] + (a[i] - a[i-1]) / 2;
            largest = a[i] - a[i-1] - 1;
        }
    }
    int ans = smallest;
    int endlen = d - a[n-1] - 1;

    int old = a[f];
    if (f > -1) {
        if (endlen > largest / 2 - ((largest & 1) ^ 1)) {
            a[f] = d;
        } else {
            a[f] = midpoint;
        }
        vector <int> b = a;
        sort (b.begin(), b.end());
        int cur = b[0] - 1;
        for (int i = 1; i < n; i++) {
            cur = min(cur, b[i] - b[i-1] - 1);
        }
        ans = max(ans, cur);
        if (f > 0 && f < n - 1) {
            a[f] = a[f-1] + (a[f+1] - a[f-1]) / 2;
        } else if (f < n - 1) {
            a[f] = 1 + (a[f+1] - 1) / 2;
        } else {
            a[f] = d;
        }
        b = a;
        sort (b.begin(), b.end());
        cur = b[0] - 1;
        for (int i = 1; i < n; i++) {
            cur = min(cur, b[i] - b[i-1] - 1);
        }
        ans = max(ans, cur);
        a[f] = old;
    }

    old = a[s];
    if (endlen > largest / 2 - ((largest & 1) ^ 1)) {
        a[s] = d;
    } else {
        a[s] = midpoint;
    }
    vector <int> b = a;
    sort(b.begin(), b.end());
    int cur = b[0] - 1;
    for (int i = 1; i < n; i++) {
        cur = min(cur, b[i] - b[i-1] - 1);
    }
    ans = max(ans, cur);
    // if (test == 10) debug (ans, b);
    if (s > 0 && s < n - 1) {
        a[s] = a[s-1] + (a[s+1] - a[s-1]) / 2;
    } else if (s < n - 1) {
        a[s] = 1 + (a[s+1] - 1) / 2;
    } else {
        a[s] = d;
    }
    b = a;
    sort(b.begin(), b.end());
    cur = b[0] - 1;
    for (int i = 1; i < n; i++) {
        cur = min(cur, b[i] - b[i-1] - 1);
    }
    ans = max(ans, cur);

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
