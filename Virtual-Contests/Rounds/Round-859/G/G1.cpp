#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MX = (int)1e4 + 5;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    vector<bool> s(MX, false);
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (i > 0 && !s[a[i]]) {
            ans = false;
        } else if (i == 0) {
            ans &= a[i] == 1;
        }
        vector<bool> other(MX, false);
        for (int j = 0; j <= 5000; j++) {
            if (!s[j]) continue;
            int val = j + a[i];
            other[val] = true;
        }
        for (int j = 0; j < MX; j++) {
            if (other[j]) s[j] = true;
        }
        s[a[i]] = true;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
