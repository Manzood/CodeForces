#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

struct person {
    int x;
    int y;
};

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        vector <int> ver(n);
        vector <int> hor(m);
        vector <person> p(k);
        vector <int> vercnt(n, 0);
        vector <int> horcnt(m, 0);
        vector <int> veron(n, 0);
        vector <int> horon(n, 0);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &ver[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%lld", &hor[i]);
        }

        for (int i = 0; i < k; i++) {
            scanf("%lld%lld", &p[i].x, &p[i].y);
            int indx = lower_bound(ver.begin(), ver.end(), p[i].x) - ver.begin();
            int indy = lower_bound(hor.begin(), hor.end(), p[i].y) - hor.begin();
            if (p[i].x < ver[indx]) vercnt[indx]++;
            if (p[i].y < hor[indy]) horcnt[indy]++;
        }
        // iterate through each point instead

        // n * (n - 1) / 2
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int val = vercnt[i];
            debug (vercnt[i]);
            ans += (val * (val - 1)) / 2;
        }

        for (int i = 0; i < m; i++) {
            int val = horcnt[i];
            ans += (val * (val - 1)) / 2;
        }

        printf("%lld\n", ans);
    }
}
