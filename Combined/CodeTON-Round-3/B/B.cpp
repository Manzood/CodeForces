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
    int ans = 0;
    int zeroes = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            zeroes++;
        else
            ones++;
    }
    ans = ones * zeroes;
    zeroes = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zeroes++;
        } else {
            zeroes = 0;
        }
        ans = max(ans, zeroes * zeroes);
    }
    zeroes = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            zeroes++;
        } else {
            zeroes = 0;
        }
        ans = max(ans, zeroes * zeroes);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
