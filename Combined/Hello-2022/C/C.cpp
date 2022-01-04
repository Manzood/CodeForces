#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int query (int i) {
    int q;
    cout << "? " << i + 1 << endl;
    cin >> q;
    return q - 1;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        int ind = 0;
        vector <bool> marked (n, false);
        int first = -2;
        int prev = -2;
        vector <int> p(n, -1);
        bool failed = false;
        // bool found_others = false;

        while (cnt < n && !failed) {
            int q = query (ind);
            // debug (ind, cnt);
            if (q == -1) {
                failed = true;
                break;
            }
            if (first == -2) {
                first = q;
                prev = q;
                continue;
            } else {
                if (q == first) {
                    if (prev != -2) {
                        p[prev] = q + 1;
                        marked[prev] = true;
                        cnt++;
                    }

                    while (ind < n && marked[++ind]);
                    first = -2;
                    prev = -2;
                    continue;
                }
            }
            p[prev] = q + 1;
            marked[prev] = true;
            prev = q;
            cnt++;
        }

        if (!failed) {
            // printing answer
            cout << "! ";
            for (int i = 0; i < n; i++) {
                assert (p[i] != -1);
                cout << p[i] << " ";
            }
            cout << endl;
        }
    }
}
