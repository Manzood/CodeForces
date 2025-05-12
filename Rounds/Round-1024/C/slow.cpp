#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    vector<int> b, index;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > 1) {
            b.push_back(a[i]);
            index.push_back(i);
        }
    }

    // binary search
    int ans = 0;

    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        set<int> rem;
        for (int i = 1; i <= mid; i++) rem.insert(i);
        vector<bool> used(n, false);

        int ind = n;
        int cnt = 0;
        for (int i = 0; i < n && !rem.empty(); i++) {
            auto it = rem.end();
            it--;
            if (a[i] > *it) {
                rem.erase(it);
                used[i] = true;
                cnt++;
            } else {
                it = upper_bound(rem.begin(), rem.end(), a[i]);
                if (it == rem.begin()) continue;
                it--;
                rem.erase(it);
                used[i] = true;
                cnt++;
            }

            if (rem.empty()) {
                ind = i;
                break;
            }
        }

        rem.clear();
        for (int i = 1; i <= mid; i++) rem.insert(i);

        int ind2 = -1;
        for (int i = n - 1; i >= 0 && !rem.empty(); i--) {
            auto it = rem.end();
            it--;
            if (a[i] > *it) {
                rem.erase(it);
                used[i] = true;
            } else {
                it = upper_bound(rem.begin(), rem.end(), a[i]);
                if (it == rem.begin()) continue;
                it--;
                rem.erase(it);
                used[i] = true;
            }

            if (rem.empty()) {
                ind2 = i;
                break;
            }
        }

        if (ind < ind2) {
            vector<int> l;
            int val = 0;
            for (int i = 0; i < n; i++) {
                if (used[i]) {
                    if (cnt > 0) {
                        l.push_back(i);
                        cnt--;
                    } else {
                        val += i - l.back();
                        l.pop_back();
                    }
                }
            }

            ans = max(ans, val);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
