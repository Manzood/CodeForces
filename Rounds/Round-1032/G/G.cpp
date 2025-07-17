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

    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = (s[i] == '1' ? 1LL : -1LL) + pref[i];
    }
    sort(pref.begin(), pref.end());
    vector<int> prefprime(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        if (i == 0)
            prefprime[i] = pref[i];
        else {
            prefprime[i] = prefprime[i - 1] + pref[i];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i * pref[i] - prefprime[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        ans += i * (n - i + 1);
    }

    ans /= 2;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
