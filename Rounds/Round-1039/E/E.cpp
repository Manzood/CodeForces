#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

class segTree {
    int _n, size;
    vector<int64_t> mx;

   public:
    segTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        _n = 2 * size - 1;
        mx.assign(_n, 0LL);
    }

    void build(vector<int>& a) {
        int n = (int)a.size(), zeroes = size - n, cur = _n - 1;
        while (cur >= _n - size) {
            if (zeroes) {
                cur--, zeroes--;
            } else {
                mx[cur] = a[cur - (_n - size)];
                cur--;
            }
        }
        for (int i = _n - 1; i > 0; i--) mx[(i - 1) / 2] += mx[i];
    }

    int64_t getSum(int node, int lx, int rx, int left, int right) {
        if (lx > right || rx < left) return 0;
        if (lx >= left && rx <= right) return mx[node];
        int64_t s =
            getSum(2 * node + 1, lx, rx - (rx - lx + 1) / 2, left, right);
        s += getSum(2 * node + 2, lx + (rx - lx + 1) / 2, rx, left, right);
        return s;
    }

    int64_t getSum(int left, int right) {
        return getSum(0, 0, size - 1, left, right - 1);
    }

    void set(int ind, int val) {
        int cur = _n / 2 + ind;
        int64_t diff = val - mx[cur];
        while (cur > 0) {
            mx[cur] += diff;
            cur = (cur - 1) / 2;
        }
        mx[0] += diff;
    }
};

bool check(vector<int>& a, int val, int k) {
    int n = (int)a.size();
    segTree st(n);

    int cur = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] >= val) {
            st.set(i, 1);
            cur++;
        }
    }
    if (cur >= (k + 1) / 2) {
        return true;
    }

    int ptr = 0;
    for (int i = k; i < n; i++) {
        if (a[i] >= val) {
            st.set(i, 1);
            cur++;
        }

        int tmp = st.getSum(ptr, i - k + 1);
        if (tmp <= (i - k + 1 - ptr) / 2) {
            ptr = i - k + 1;
            cur -= tmp;
        }

        if (cur >= (i - ptr + 2) / 2) {  // TODO check this one
            return true;
        }
    }

    return false;
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int low = 1, high = n, ans = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(a, mid, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    segTree st(n);
    int cur = 0, l = -1, r = -1;
    for (int i = 0; i < k; i++) {
        if (a[i] >= ans) {
            st.set(i, 1);
            cur++;
        }
    }
    if (cur >= (k + 1) / 2) {
        l = 0, r = k - 1;
    }

    int ptr = 0;
    for (int i = k; i < n; i++) {
        if (a[i] >= ans) {
            st.set(i, 1);
            cur++;
        }

        int tmp = st.getSum(ptr, i - k + 1);
        if (tmp <= (i - k + 1 - ptr) / 2) {
            ptr = i - k + 1;
            cur -= tmp;
        }

        if (cur >= (i - ptr + 2) / 2) {  // TODO check this one
            l = ptr, r = i;
        }
    }

    printf("%lld %lld %lld\n", ans, l + 1, r + 1);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
