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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    multiset<int> s;
    for (auto x : b) {
        s.insert(x);
    }

    vector<int> c;
    for (int i = 0; i < n; i++) {
        int smallest = *s.begin();
        auto it = s.lower_bound(n - a[i]);
        int over = smallest;
        if (it != s.end()) {
            over = *it;
        }

        if (((a[i] + smallest) % n) <= ((a[i] + over) % n)) {
            s.erase(s.begin());
            c.push_back((a[i] + smallest) % n);
        } else {
            s.erase(s.lower_bound(n - a[i]));
            c.push_back((a[i] + over) % n);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", c[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
