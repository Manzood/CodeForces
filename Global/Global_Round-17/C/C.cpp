#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &a[i], &b[i]);
        }

        min_heap<pair <int, int>> pq;
        int ans = 1;
        pq.push ({a[0], a[0]});

        debug (pq.size());
        debug (pq.top());
        for (int i = 1; i < n; i++) {
            pair <int, int> top_val = pq.top();

            while (pq.size() > 0 && top_val.first <= 0) {
                debug ("popping", pq.top());
                pq.pop();
                // sz--;
                top_val = pq.top();
                if (pq.size() > 0) {
                    auto new_top = pq.top();
                    new_top.first = new_top.first - (int) pq.size() + 1;
                    pq.pop();
                    pq.push(new_top);
                }
                debug (pq.size(), pq.top());
            }

            if (b[i] >= (int) pq.size()) {
                if (pq.size() > 0) {
                    top_val = pq.top();
                    pq.pop();
                    top_val.first--;
                    pq.push(top_val);
                }
                pq.push({a[i], a[i]});

                // inserting new value
                // sz++;
                ans = max ((int)pq.size(), ans);
            }
            debug (i, pq.size());
            debug (pq.top())
            ans = max ((int) pq.size(), ans);
        }
        printf("%lld\n", ans);
    }
}
