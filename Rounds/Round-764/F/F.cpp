#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

int query (int val) {
    cout << "+ " << val << endl;
    int answer;
    cin >> answer;
    return answer;
}

int32_t main() {
    int n;
    cin >> n;
    int x = 0;
    int low = 1;
    int high = n - 1;
    int prev_query = 0;
    int div = 1;
    int sum_of_queries = 0;
    int mid = (low + high) / 2;

    int num_queries = 0;
    while (low < high && num_queries <= 10) {
        mid = (low + high) / 2;
        debug (low, high, mid);
        // fix query each time
        int ans = query (prev_query + mid);
        num_queries++;

        sum_of_queries += prev_query + mid;

        if (ans >= div) {
            low = mid + 1;
            prev_query = n - mid;
            div++;
        } else {
            high = mid - 1;
            prev_query = 0;
        }
        debug (low, high);
    }

    x = (low + high) / 2;

    // while (low < high) {
    //     int val = (low + high) / 2;
    //     // debug (low, high);
    //     int ans = query (prev_query + val);
    //     sum_of_queries += prev_query + val;
    //
    //     prev_query = 0;
    //     if (ans >= div) {
    //         low = n - val;
    //     } else {
    //         high = n - val - 1;
    //         prev_query +=  n - val;
    //     }
    //
    //     div++;
    //     prev_query += n - val;
    // }

    cout << "! " << x + sum_of_queries << endl;
}
