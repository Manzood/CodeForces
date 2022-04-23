#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int w) {
    int response;
    cout << "? " << w << endl;
    cin >> response;
    return response;
}

int search(int w, int h) {
    int index = -1;
    // search for h + 1
    int low = 0, high = w;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int new_h = query(mid);
        if (new_h > h + 1) {
            low = mid;
        }
    }

    return index;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    int w = (int) 1e6;
    int cur = 1;
    // binary search, somehow
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
