#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    int cuts = 0;
    string s = a + b;
    for (int i = 1; i < n + m; i++) {
        if (s[i] == s[i - 1]) cuts++;
    }
    bool ans = (cuts <= 1);
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
