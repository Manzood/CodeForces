#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = (int)1e18 + 7;

struct segtree {  // zero based indexing
    int size;
    vector<long long> sum;
    vector<long long> m;
    vector<long long> mx;
    segtree(int n) {
        // makes size a power of two GE n
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2 * size - 1, 0);
        m.assign(2 * size - 1, inf);
        mx.assign(2 * size - 1, -inf);
    }
    void build(vector<int>& a) {
        int n = (int)a.size();
        int numzeroes = size - n;
        int counter = 0;
        for (int i = 2 * size - 2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
                m[i] = inf;
                mx[i] = -inf;
            } else if (n > 0) {
                sum[i] = a[--n];
                m[i] = a[n];
                mx[i] = a[n];
            } else {
                sum[i] += sum[2 * i + 1] + sum[2 * i + 2];
                m[i] = min(m[2 * i + 1], m[2 * i + 2]);
                mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
            }
        }
    }
    void set(int i, int v) {  // setting index i to element v
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            m[x] = v;
            mx[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        m[x] = min(m[2 * x + 1], m[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
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
    long long getmin(int left, int right) {  // returns min between indexes
                                             // [left, right - 1], inclusive
        return getmin(left, right, 0, 0, size);
    }
    long long getmin(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return inf;
        if (lx >= left && rx <= right) return m[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmin(left, right, 2 * x + 1, lx, mid);
        long long s2 = getmin(left, right, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }
    long long getmax(int left, int right) {  // returns max between indexes
                                             // [left, right - 1], inclusive
        return getmax(left, right, 0, 0, size);
    }
    long long getmax(int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return -inf;
        if (lx >= left && rx <= right) return mx[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmax(left, right, 2 * x + 1, lx, mid);
        long long s2 = getmax(left, right, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), pref(n, 0), suff(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pref[i] += a[i] + (i > 0 ? pref[i - 1] : 0LL);
    }
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] + a[i];
    vector<int> prefprime(n, 0);
    for (int i = 0; i < n; i++)
        prefprime[i] = pref[i] + (i > 0 ? prefprime[i - 1] : 0LL);

    vector<int> rsum(n, 0);
    rsum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rsum[i] = rsum[i + 1] + (n - i) * a[i];
    }

    vector<int> rowOffset(n, 0);
    int temp = n;
    rowOffset[0] = n;
    for (int i = 1; i < n; i++) rowOffset[i] = rowOffset[i - 1] + --temp;

    segtree st(n);
    st.build(rsum);

    int q;
    scanf("%lld", &q);
    for (int query = 0; query < q; query++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        int x1 = lower_bound(rowOffset.begin(), rowOffset.end(), l) -
                 rowOffset.begin();
        int y1 = (n - x1) - (rowOffset[x1] - l) - 1 + x1;
        int x2 = lower_bound(rowOffset.begin(), rowOffset.end(), r) -
                 rowOffset.begin();
        int y2 = (n - x2) - (rowOffset[x2] - r) - 1 + x2;
        int ans = 0;
        if (x2 - x1 > 1) ans += st.getsum(x1 + 1, x2);
        if (x2 > x1) {
            // add x1 first
            int v1 = y1 > 0 ? prefprime[y1 - 1] : 0LL;
            int v2 = x1 > 0 ? pref[x1 - 1] : 0LL;
            ans += prefprime[n - 1] - v1 - (n - y1) * v2;
            // add x2
            ans += prefprime[y2] - prefprime[x2 - 1] -
                   (y2 - x2 + 1) * pref[x2 - 1];
        } else {
            int v1 = y1 > 0 ? prefprime[y1 - 1] : 0LL;
            int v2 = x1 > 0 ? pref[x1 - 1] : 0LL;
            ans += prefprime[y2] - v1 - (y2 - y1 + 1) * v2;
        }
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
