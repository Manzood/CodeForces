#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, s;
        scanf("%lld%lld", &n, &s);
        int t1, t2;
        vector <int> w(n-1);
        int sum = 0;
        for (int i = 0; i < n-1; i++) {
            scanf("%lld%lld%lld", &t1, &t2, &w[i]);
            sum += w[i];
        }
        make_heap (w.begin(), w.end());
        int moves = 0;
        while (sum > s) {
            // debug(sum);
            sum -= w.front();
            int temp = w.front();
            // debug(temp);
            for (auto x: w) {
                printf("%lld ", x);
            }
            printf("\n");
            pop_heap(w.begin(), w.end());
            w.pop_back();
            w.push_back(temp/2LL);
            push_heap(w.begin(), w.end());
            sum += temp/2LL;
            moves++;
        }
            for (auto x: w) {
                printf("%lld ", x);
            }
            printf("\n");
        printf("%lld\n", moves);
    }
}   