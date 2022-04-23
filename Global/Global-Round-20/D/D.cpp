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
    vector <int> cnt_a(n + 1, 0);
    vector <int> cnt_b(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt_a[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        cnt_b[b[i]]++;
    }
    int aptr = n - 1;
    bool possible = true;
    for (int i = n - 1; i >= 0; i--) {
        while (aptr >= 0 && a[aptr] != b[i]) {
            cnt_a[a[aptr]]--;
            aptr--;
        }
        if (aptr < 0) {
            possible = false;
            break;
        }
        if (cnt_b[b[i]] > cnt_a[b[i]]) possible = false;
        cnt_b[b[i]]--;
    }
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
