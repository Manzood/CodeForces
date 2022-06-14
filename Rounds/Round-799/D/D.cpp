#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int x;
    scanf("%lld", &x);
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    set <pair <int, int>> times;
    int ans = 0;
    while (!(times.count({h, m}))) {
        times.insert({h, m});
        if (h / 10 == m % 10 && h % 10 == m / 10) {
            ans++;
        }
        h += x / 60;
        m += x % 60;
        if (m > 59) {
            m -= 60;
            h++;
        }
        if (h > 23) h -= 24;
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
