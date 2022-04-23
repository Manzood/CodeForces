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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    vector <int> cnt(n + 1, 0);
    int required = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        int rem = i + 1 - cnt[a[i]];
        if (rem >= cnt[a[i]]) required++;
    }
    int sadness = 0;
    vector <int> next(n + 1, 0);
    vector <int> first(n + 1, -1);
    vector <int> p(n + 1, -1);
    for (int i = 0; i < n; i++) {
        if (first[a[i]] == -1) first[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (p[a[i]] == -1) {
            next[i] = first[a[i]];
            p[a[i]] = i;
        } else {
            next[i] = p[a[i]];
            p[a[i]] = i;
        }
    }
    debug(next);
    for (int i = 0; i < n; i++) {
        while (b[i] != a[i]) {
            int ind = next[b[i]];
            swap(b[i], b[ind]);
            sadness++;
        }
    }
    if (sadness < required) {
        printf("WA\n");
    } else {
        printf("AC\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
