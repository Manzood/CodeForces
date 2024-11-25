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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            int ind = i;
            for (int j = i; j < n; j++) {
                if (a[j] == i + 1) {
                    ind = j;
                }
            }
            reverse(a.begin() + i, a.begin() + ind + 1);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
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
