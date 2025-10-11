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
    string s;
    cin >> s;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ones++;
    }
    int cnt = 0;
    for (int i = n - ones; i < n; i++) {
        if (s[i] != '1') cnt++;
    }
    printf("%lld\n", cnt);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
