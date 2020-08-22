#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(;t--;)
    {
        int m, sum = 0, x0, x1, x2, y0, y1, y2;
        cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
        m = min(x0, y2); // min (a, z)
        x0 -= m;  // a -= min (a, z);
        y2 -= m;  // z -= min (a, z);

        m = min(x1, y0); // min(b, x);
        x1 -= m; // b -= min(b, x);
        y0 -= m; // x -= min(b, x);

        m = min(x2, y1); // min(c, y);
        x2 -= m; // c -= min(c, y);
        y1 -= m; // y -= min(c, y);
        sum += 2 * m; // sum += 2 * min(c, y)
        sum -= 2 * min(x1, y2); // sum -= 2 * min(b, z);

        cout << sum << endl;
    }
}