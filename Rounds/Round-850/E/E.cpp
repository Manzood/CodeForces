#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = (int)1e9 + 7;

struct segtree {  // zero based indexing
    int size;
    vector<long long> sum;
    segtree(int n) {
        // makes size a power of two GE n
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2 * size - 1, 0);
    }
    void build(vector<int>& a) {
        int n = (int)a.size();
        int numzeroes = size - n;
        int counter = 0;
        for (int i = 2 * size - 2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
            } else if (n > 0) {
                sum[i] = a[--n];
            } else {
                sum[i] += sum[2 * i + 1] + sum[2 * i + 2];
            }
        }
    }
    void set(int i, int v) {  // setting index i to element v
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
    }
    void inc(int i) { inc(i, 0, 0, size); }
    void inc(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x]++;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            inc(i, 2 * x + 1, lx, mid);
        else
            inc(i, 2 * x + 2, mid, rx);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
    }
    long long getsum(int left, int right) {  // returns sum between indexes
                                             // [left, right - 1], inclusive
        return getsum(left, right, 0, 0, size);
    }
    long long getsum(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int mid = (lx + rx) / 2;
        long long s1 = getsum(left, right, 2 * x + 1, lx, mid);
        long long s2 = getsum(left, right, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    segtree st(n + 1);
    vector<int> tmp(n + 1, 0);
    st.build(tmp);
    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int less = st.getsum(0, a[i] + 1);
        int more = st.getsum(a[i] + 1, n + 1);
        if (a[i] > less) {
            cur += a[i] - less - 1;
            cur -= more;
        }
        st.inc(a[i]);
        ans.push_back(cur);
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
