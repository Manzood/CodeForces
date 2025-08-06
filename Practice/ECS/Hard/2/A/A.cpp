#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(vector<int>& ans, vector<int>& nxt) {
    int n = (int)ans.size();
    vector<int> copy = ans;
    vector<int> tmp(n);
    iota(tmp.begin(), tmp.end(), 1);
    sort(copy.begin(), copy.end());

    if (copy != tmp) {
        return false;
    }

    stack<int> st;
    vector<int> nge(n, n + 1);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && ans[st.top()] <= ans[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top() + 1;
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (nxt[i] == -1) continue;
        if (nge[i] != nxt[i]) return false;
    }

    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            adj[a[i] - 1].push_back(i);
        }
    }

    vector<int> ans(n, 0);
    int val = n;
    for (int i = n; i >= 0; i--) {
        if (i < n) {
            if (adj[i].size()) {
                if (ans[i] == 0) ans[i] = val--;
            }
        }
        for (auto x : adj[i]) {
            ans[x] = val--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) ans[i] = val--;
    }

    if (!check(ans, a)) {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
