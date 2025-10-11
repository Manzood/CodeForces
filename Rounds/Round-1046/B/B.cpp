#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;

    int cnt = 0;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
        } else {
            cnt = 0;
        }

        if (cnt >= k) {
            possible = false;
        }
    }

    vector<int> p(n);
    int val = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') p[i] = val++;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') p[i] = val++;
    }

    if (possible) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%lld ", p[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
