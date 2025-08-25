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
    vector<int> a(n), pos(n + 2, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pos[a[i]] = i;
    }

    stack<int> st;
    vector<int> nge(n, n), pge(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() < a[i]) st.pop();
        if (!st.empty()) pge[i] = pos[st.top()];
        st.push(a[i]);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() < a[i]) st.pop();
        if (!st.empty()) nge[i] = pos[st.top()];
        st.push(a[i]);
    }

    int ans = 0;
    for (int x = 1; x <= n; x++) {
        int i = pos[x], l = pge[i], r = nge[i];
        if (i - l < r - i) {
            for (int j = l + 1; j < i; j++) {
                if (pos[a[i] - a[j]] > i && pos[a[i] - a[j]] < r) ans++;
            }
        } else {
            for (int j = i + 1; j < r; j++) {
                if (pos[a[i] - a[j]] < i && pos[a[i] - a[j]] > l) ans++;
            }
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
