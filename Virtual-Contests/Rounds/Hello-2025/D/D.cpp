#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int INF = (int)1e9 + 7;

struct segtree {  // zero based indexing
    int size;
    vector<long long> m1, m2;
    vector<long long> mx1, mx2;
    vector<int> best;
    segtree(int n) {
        size = 1;
        while (size < n) size *= 2;
        m1.assign(2 * size - 1, INF);
        mx1.assign(2 * size - 1, -INF);
        m2.assign(2 * size - 1, INF);
        mx2.assign(2 * size - 1, -INF);
        best.assign(2 * size - 1, 0LL);
    }
    void build(vector<int>& a) {
        int n = (int)a.size();
        int numzeroes = size - n;
        int counter = 0;
        for (int i = 2 * size - 2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                m1[i] = INF;
                mx1[i] = -INF;
                m2[i] = INF;
                mx2[i] = -INF;
                best[i] = -INF;
            } else if (n > 0) {
                --n;
                m1[i] = a[n] - n;
                mx1[i] = a[n] - n;
                m2[i] = a[n] + n;
                mx2[i] = a[n] + n;
                best[i] = 0;
            } else {
                m1[i] = min(m1[2 * i + 1], m1[2 * i + 2]);
                mx1[i] = max(mx1[2 * i + 1], mx1[2 * i + 2]);
                m2[i] = min(m2[2 * i + 1], m2[2 * i + 2]);
                mx2[i] = max(mx2[2 * i + 1], mx2[2 * i + 2]);
                best[i] = max({best[2 * i + 1], best[2 * i + 2],
                               mx1[2 * i + 2] - m1[2 * i + 1],
                               mx2[2 * i + 1] - m2[2 * i + 2]});
            }
        }
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            m1[x] = v - i;
            mx1[x] = v - i;
            m2[x] = v + i;
            mx2[x] = v + i;
            best[x] = 0;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        m1[x] = min(m1[2 * x + 1], m1[2 * x + 2]);
        mx1[x] = max(mx1[2 * x + 1], mx1[2 * x + 2]);
        m2[x] = min(m2[2 * x + 1], m2[2 * x + 2]);
        mx2[x] = max(mx2[2 * x + 1], mx2[2 * x + 2]);
        best[x] = max({best[2 * x + 1], best[2 * x + 2],
                       mx1[2 * x + 2] - m1[2 * x + 1],
                       mx2[2 * x + 1] - m2[2 * x + 2]});
    }
    long long getmin1(int left, int right) {
        return getmin(left, right, 0, 0, size, m1);
    }
    long long getmin2(int left, int right) {
        return getmin(left, right, 0, 0, size, m2);
    }
    long long getmin(int left, int right, int x, int lx, int rx,
                     vector<int>& m) {
        if (lx >= right || left >= rx) return INF;
        if (lx >= left && rx <= right) return m[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmin(left, right, 2 * x + 1, lx, mid, m);
        long long s2 = getmin(left, right, 2 * x + 2, mid, rx, m);
        return min(s1, s2);
    }
    long long getmax1(int left, int right) {
        return getmax(left, right, 0, 0, size, mx1);
    }
    long long getmax2(int left, int right) {
        return getmax(left, right, 0, 0, size, mx2);
    }
    long long getmax(int left, int right, int x, int lx, int rx,
                     vector<int>& mx) {
        if (lx >= right || left >= rx) return -INF;
        if (lx >= left && rx <= right) return mx[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmax(left, right, 2 * x + 1, lx, mid, mx);
        long long s2 = getmax(left, right, 2 * x + 2, mid, rx, mx);
        return max(s1, s2);
    }
    int getAns(int left, int right) { return getAns(left, right, 0, 0, size); }
    int getAns(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return -INF;
        if (lx >= left && rx <= right) return best[x];
        int mid = (lx + rx) / 2;
        long long s1 = getAns(left, right, 2 * x + 1, lx, mid);
        long long s2 = getAns(left, right, 2 * x + 2, mid, rx);
        int ret = max(s1, s2);
        ret = max(ret, getmax1(mid, rx) - getmin1(lx, mid));
        ret = max(ret, getmax2(lx, mid) - getmin2(mid, rx));
        return ret;
    }
};

// a[l] - a[r] - (r - l)
// a[l] + l - (a[r] + r)

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    segtree st(n);
    st.build(a);
    printf("%lld\n", st.getAns(0, n));

    for (int query = 1; query <= q; query++) {
        int ind, x;
        scanf("%lld%lld", &ind, &x);
        ind--;
        st.set(ind, x);
        printf("%lld\n", st.getAns(0, n));
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
