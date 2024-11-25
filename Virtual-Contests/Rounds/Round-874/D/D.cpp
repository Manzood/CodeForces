#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool compare(vector<int>& a, vector<int>& b) {
    // returns true if a > b
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }
    return false;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int ind = i - 1;
        vector<int> cur(n);
        while (ind >= 0) {
            if (a[ind] >= a[0])
                ind--;
            else
                break;
        }
        int tot = 0;
        for (int j = i + 1; j < n; j++) cur[tot++] = a[j];
        for (int j = i; j > ind; j--) cur[tot++] = a[j];
        for (int j = 0; j <= ind; j++) cur[tot++] = a[j];
        assert(tot == n);
        if (compare(cur, ans)) ans = cur;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", ans[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
