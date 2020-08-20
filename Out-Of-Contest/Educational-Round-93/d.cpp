#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    vector <int> red(r), green(g), blue(b);
    for (int i = 0; i < r; i++) scanf("%d", &red[i]);
    for (int i = 0; i < g; i++) scanf("%d", &green[i]);
    for (int i = 0; i < b; i++) scanf("%d", &blue[i]);
    sort(red.begin(), red.end()); sort(green.begin(), green.end()); sort(blue.begin(), blue.end());
    long long ans = 0;
    bool rcheck = true, gcheck = true, bcheck = true;
    int count = 3;
    while (count > 1) {
        if (count > 2) {
            if (red.back() == green.back() && red.back() == blue.back()) {
                if (sz(red) >= 2 && red[sz(red) - 2] >= blue[max(sz(blue)-2, 0)] && red[sz(red) - 2] >= green[max(sz(green)-2, 0)]) {
                    ans += red.back() * green.back();
                    red.pop_back(); green.pop_back();
                }
                if (sz(blue) >= 2 && blue[sz(blue) - 2] >= red[max(sz(red)-2, 0)] && blue[sz(blue) - 2] >= green[max(sz(green)-2, 0)]) {
                    ans += blue.back() * green.back();
                    blue.pop_back(); green.pop_back();
                }
                if (sz(green) >= 2 && green[sz(green) - 2] >= blue[max(sz(blue)-2, 0)] && green[sz(green) - 2] >= red[max(sz(red)-2, 0)]) {
                    ans += red.back() * green.back();
                    red.pop_back(); green.pop_back();
                }
            }
            else if (rcheck && red.back() <= green.back() && red.back() <= blue.back()) {
                ans += green.back() * blue.back();
                green.pop_back(); blue.pop_back();
            }
            else if (gcheck && green.back() <= red.back() && green.back() <= blue.back()) {
                ans += red.back() * blue.back();
                red.pop_back(); blue.pop_back();
            }
            else if (bcheck && blue.back() <= red.back() && blue.back() <= green.back()) {
                ans += red.back() * green.back();
                red.pop_back(); green.pop_back();
            }
        }
        else {
            if (!rcheck) {
                ans += green.back() * blue.back();
                green.pop_back(); blue.pop_back();
            }
            else if (!gcheck) {
                ans += red.back() * blue.back();
                red.pop_back(); blue.pop_back();
            }
            else if (!bcheck) {
                ans += green.back() * red.back();
                red.pop_back(); green.pop_back();
            }
        }
        if (rcheck && sz(red) == 0) {
            rcheck = false;
            count--;
        }
        if (gcheck && sz(green) == 0) {
            gcheck = false;
            count--;
        }
        if (bcheck && sz(blue) == 0) {
            bcheck = false;
            count--;
        }
    }
    printf("%lld\n", ans);
}