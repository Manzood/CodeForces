#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, l;
		scanf("%d%d%d", &n, &k, &l);
		vector <int> a(n);
		for (int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int safe = -1;
		int current = 0;
		int direction = 1;
		bool possible = true;
		debug(k);
		for (int i=0; i<n; i++) {
			if (a[i] + current > l && a[i] + (i-safe) > l) {
				possible = false;
				break;
			}
			else if (a[i] + k <= l) safe = i;	
			if (current == k) direction = -1;
			if (current == 0 && direction == -1) direction = 1;
			current += direction;
		}	
		if (possible) printf("Yes\n");
		else printf("No\n");
	}
}