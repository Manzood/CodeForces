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
		int currentdir=1;
		bool possible = true;
		int leeway = 0;
		for (int i=0; i<n; i++) {
			if (a[i] + k <= l) {
				safe = i;
			}	
			if (a[i] > l) possible = false;
			if (i == safe+1) {
				leeway = l - a[i];
			}
			if (a[i] + current - leeway> l) { 
				possible = false;
			}
			else {
				if (a[i] + current <= l) {
					leeway = l - a[i] - current;
				}
			}
			if (leeway > 0) leeway--;
			if (current == k) currentdir=-1;
			if (current == 0) currentdir=1;
			current+=currentdir;
		}	
		if (possible) printf("Yes\n");
		else printf("No\n");
	}
}