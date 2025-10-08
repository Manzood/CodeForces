#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get(vector<int>& a) {
    int n = (int)a.size();
    int last = 0, ret = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ret += (i - last) * (n - i);
            last = i;
        }
    }
    return ret;
}

void put(int x, int y, vector<int>& a) {
    int val = a[x];
    for (int i = x; i > y; i--) {
        a[i] = a[i - 1];
    }
    a[y] = val;
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    int val = 0;
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    debug(ans);

    for (int i = n - 1; i >= 0; i--) {
        int ind = n - 1;
        for (int j = 0; j < n; j++) {
            if (ans[ind] == i + 1) ind = j;
        }
        for (int j = 0; j < ind - 1; j++) {
            vector<int> cpy = ans;
            put(ind, j, cpy);
            debug(cpy, get(cpy));
            if (get(cpy) <= k) {
                ans = cpy;
                break;
            }
        }
    }

    if (val == k) {
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    } else {
        printf("0\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
