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
    // calculate log
    // int log = 1;
    // while (log < n) log *= 2;
    // int val = log / 2;
    int low = 1;
    int high = n - 1;
    // debug (val);
    int prev_query = 0;
    int div = 1;
    int sum_of_queries = 0;

    while (low < high) {
        int val = (low + high) / 2;
        // debug (low, high);
        int ans = query (prev_query + val);
        sum_of_queries += prev_query + val;

        prev_query = 0;
        if (ans >= div) {
            low = n - val;
        } else {
            high = n - val - 1;
            prev_query +=  n - val;
        }

        div++;
        prev_query += n - val;
    }

    x = min(low, high);

    // while (val > 0) {
    //     int ans = query (prev_query + val);
    //     if (ans >= div) {
    //         sum += val;
    //         x += val;
    //     }
    //     prev_query = n - val;
    //     val /= 2;
    // }
    debug (x);
    cout << "! " << x + sum_of_queries << endl;
}
