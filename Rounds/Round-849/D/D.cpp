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
    vector<int> pref(n, 0), suff(n, 0);
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
        pref[i] = (int)st.size();
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        st.insert(s[i]);
        suff[i] = (int)st.size();
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, pref[i] + suff[i + 1]);
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
