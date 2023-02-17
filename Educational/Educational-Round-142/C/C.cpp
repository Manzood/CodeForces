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
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pos[a[i] - 1] = i;
    }
    int ind = n / 2 - 1;
    while (ind >= 0 && pos[ind + 1] > pos[ind] &&
           pos[n - 1 - ind] > pos[n - 2 - ind]) {
        ind--;
    }
    printf("%lld\n", ind + 1);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
