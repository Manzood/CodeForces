#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> create(int n, int k, int mx) {
    int step = max(mx + 1, k);
    vector<int> ret(n, 0);
    for (int i = 0; i <= mx; i++) {
        for (int j = i; j < n; j += step) {
            ret[j] = i;
        }
    }
    return ret;
}

bool check(vector<int>& a, int m, int mex) {
    int n = (int)a.size();
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 0; i <= mex; i++) {
        if (cnt[i] <= m) return false;
    }
    return true;
}

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    int low = 0, high = n + 1;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> a = create(n, k, mid);
        if (check(a, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    vector<int> a = create(n, k, ans);
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
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
