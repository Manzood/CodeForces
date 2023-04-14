#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int left, int right) {
    cout << "? " << right - left + 1 << " ";
    for (int i = left + 1; i <= right + 1; i++) {
        cout << i << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        int x = query(left, mid);
        int sum = pref[mid + 1] - pref[left];
        if (sum < x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << "! " << left + 1 << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
