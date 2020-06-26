#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		vector <int> evenpref;
		vector <int> oddpref;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (i%2==1 && i>0) {
				if (i==1) {
					evenpref.push_back(a[0]);
					oddpref.push_back(a[1]);
				}
				else {
					evenpref.push_back(evenpref[i/2-1]+a[i-1]);
					oddpref.push_back(oddpref[i/2-1]+a[i]);
				}
			}
		}
		if (n%2==1) {
			evenpref.push_back(evenpref[evenpref.size()-1]+a[n-1]);
		}
		// each time odd pref is greater than even pref, store it
		// each time even pref is greater, the previous subarray is already desirable for all future subarrrays
		// store the gain, add it to the final answer
		int m=0;
		int gain=0;
		int sum=0;
		int oddsum=0,evensum=0;
		for (int i=0;i<n;i++) {
			if (i%2==0) evensum+=a[i];
			else oddsum+=a[i];
			if (i%2==1 && oddsum>evensum) {
					gain+=a[i]-a[i-1];
					debug(gain);
			}
			else if (i%2==1 && oddsum<=evensum) {
				evensum-=oddsum;
				oddsum=0;
				gain=0;
			}
			if (i%2==0) sum+=a[i];
			m=max(gain,m);
		}
		debug(m);
		m+=sum;
		if (n%2==1) {
			m+=a[n-1];
		}
		printf("%d\n",m);
	}
}