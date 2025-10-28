#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(int val, vector<int>& a, int k, int e) {
    set<int> cnt;
    int n = (int)a.size();
    for (int i = 0; i <= a[0] && a[0] - i >= val; i++) {
        cnt.insert(i);
        if ((int)cnt.size() >= k) return true;
    }
    for (int i = 1; i < n; i++) {
        int mid = (a[i] + a[i - 1]) / 2;
        if (a[i] - mid >= val && mid - a[i - 1] >= val) cnt.insert(mid);
        int low = mid - 1, high = mid + 1;
        bool x = true, y = true;
        while (x || y) {
            if (x) {
                if (low - a[i - 1] >= val) {
                    cnt.insert(low);
                    low--;
                } else {
                    x = false;
                }
            }
            if (y) {
                if (a[i] - high >= val) {
                    cnt.insert(high);
                    high++;
                } else {
                    y = false;
                }
            }
            if ((int)cnt.size() >= k) return true;
        }
    }
    for (int i = e; i >= a[n - 1] && i - a[n - 1] >= val; i--) {
        cnt.insert(i);
        if ((int)cnt.size() >= k) return true;
    }
    return (int)cnt.size() >= k;
}

void solve([[maybe_unused]] int test) {
    int n, k, x;
    scanf("%lld%lld%lld", &n, &k, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());

    int low = 1, high = x, best = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid, a, k, x)) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    set<int> out;
    for (int i = 0; i <= a[0] && a[0] - i >= best && (int)out.size() < k; i++) {
        out.insert(i);
    }
    for (int i = 1; i < n && (int)out.size() < k; i++) {
        int mid = (a[i] + a[i - 1]) / 2;
        if (a[i] - mid >= best && mid - a[i - 1] >= best) {
            out.insert(mid);
        }
        low = mid - 1, high = mid + 1;
        bool e = true, y = true;
        while (e || y) {
            if (e) {
                if (low - a[i - 1] >= best) {
                    out.insert(low);
                    low--;
                } else {
                    e = false;
                }
            }
            if (y) {
                if (a[i] - high >= best) {
                    out.insert(high);
                    high++;
                } else {
                    y = false;
                }
            }
            if ((int)out.size() == k) break;
        }
    }
    for (int i = x;
         i >= a[n - 1] && i - a[n - 1] >= best && (int)out.size() < k; i--) {
        out.insert(i);
    }

    int cnt = 0;
    for (auto cur : out) {
        printf("%lld ", cur);
        cnt++;
        if (cnt == k) break;
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
