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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    vector<int> rbest(n, 1), lbest(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            rbest[i] += rbest[i + 1];
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            lbest[i] += lbest[i - 1];
        }
    }

    string ans;
    int l = 0, r = n - 1;
    int last = 0;

    while (l <= r) {
        if (a[l] == a[r]) {
            if (a[l] <= last) break;
            if (rbest[l] > lbest[r]) {
                for (int i = 0; i < rbest[l]; i++) {
                    ans += 'L';
                }
            } else {
                for (int i = 0; i < lbest[r]; i++) {
                    ans += 'R';
                }
            }

            break;
        } else {
            if (a[l] < a[r]) {
                if (a[l] > last) {
                    ans += 'L';
                    last = a[l];

                    l++;
                } else {
                    if (a[r] > last) {
                        ans += 'R';
                        last = a[r];

                        r--;
                    } else {
                        break;
                    }
                }
            } else {
                if (a[r] > last) {
                    ans += 'R';
                    last = a[r];

                    r--;
                } else {
                    if (a[l] > last) {
                        ans += 'L';
                        last = a[l];

                        l++;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    printf("%lld\n", (int)ans.size());
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
