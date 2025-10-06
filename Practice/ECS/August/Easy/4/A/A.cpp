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

    set<char> st;
    scanf("\n");
    for (int i = 0; i < k; i++) {
        char c;
        if (i < k - 1)
            scanf("%c ", &c);
        else
            scanf("%c", &c);
        st.insert(c);
    }

    int len = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (st.count(s[i])) {
            len++;
        } else {
            ans += len * (len + 1) / 2;
            len = 0;
        }
    }

    ans += len * (len + 1) / 2;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
