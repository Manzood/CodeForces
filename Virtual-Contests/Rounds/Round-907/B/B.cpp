#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n), x(q);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> fin;
    for (int i = 0; i < q; i++) {
        scanf("%lld", &x[i]);
        if ((int)fin.size() == 0) {
            fin.push_back(x[i]);
        } else {
            if (x[i] < fin.back()) fin.push_back(x[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto f : fin) {
            if (a[i] % (1LL << f) == 0) {
                a[i] += (1LL << (f - 1));
            }
        }
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
