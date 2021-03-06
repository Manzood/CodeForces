#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
// here, a multiset had better performance than a set and a map, which makes sense

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        n *= 2;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a.begin(), a.end());
        vector <int> ans;
        bool possible = false;
        for (int i = 0; i < n - 1; i++) {
            ans.resize(0);
            int x = a[n-1];
            multiset <int> s;
            for (int j = 0; j < n - 1; j++) {
                if (j == i) continue;
                s.insert(a[j]);
            }
            ans.push_back(a[i]);
            ans.push_back(a[n-1]);
            int cnt = n - 2;
            bool found = true;
            while (cnt && found) {
                int mx = *s.rbegin();
                s.erase(s.find(mx));
                if (s.find(x - mx) == s.end()) {
                    found = false;
                    break;
                }
                s.erase(s.find(x - mx));
                ans.push_back(x - mx);
                ans.push_back(mx);
                x = mx;
                cnt -= 2;
            }
            if (found) {
                possible = true;
                break;
            }
        }
        if (possible) {
            printf("YES\n");
            printf("%lld\n", ans[0] + ans[1]);
            for (int i = 0; i + 1 < (int)ans.size(); i += 2) {
                printf("%lld %lld\n", ans[i], ans[i+1]);
            }
        } else {
            printf("NO\n");
        }
    }
}
