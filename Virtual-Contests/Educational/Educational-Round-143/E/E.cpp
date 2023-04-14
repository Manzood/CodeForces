#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MX = (int)1e6 + 5;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> pref(n + 1, 0), suff(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = a[i] + pref[i];
    for (int i = n - 1; i >= 0; i--) suff[i] = a[i] + suff[i + 1];
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) b[i] = a[i] - i;
    for (int i = 0; i < n; i++) c[i] = a[i] - (n - 1 - i);
    vector<int> pse(n, -1), nse(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (st.size() && b[st.top()] > b[i]) st.pop();
        if (st.size()) pse[i] = st.top();
        st.push(i);
    }
    while (st.size()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() && c[st.top()] > c[i]) st.pop();
        if (st.size()) nse[i] = st.top();
        st.push(i);
    }
    vector<int> left(n, 0), right(n, 0);
    int best = (int)1e18;
    for (int i = 0; i < n; i++) {
        int ind = pse[i];
        if (ind > -1) left[i] += left[ind];
        left[i] += pref[i] - pref[ind + 1];

        int num = min(i - ind - 1, a[i]);
        int val = a[i] * num;
        val -= (num * (num + 1)) / 2;
        left[i] -= val;
    }
    for (int i = n - 1; i >= 0; i--) {
        int ind = nse[i];
        if (ind < n) right[i] += right[ind];
        right[i] += suff[i + 1] - suff[ind];

        int num = min(ind - i - 1, a[i]);
        int val = a[i] * num;
        val -= (num * (num + 1)) / 2;
        right[i] -= val;
        best = min(best, left[i] + right[i] + a[i]);
    }
    printf("%lld\n", best);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
