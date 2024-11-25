#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n,k;
	cin>>n>>k;
	vector <int> a(n);
	vector <int> sorted(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		sorted[i]=a[i];
	}
	sort(sorted.begin(),sorted.end());	
	set <int> smallest;
	for (int i=0;i<k;i++) {
		smallest.insert(sorted[i]);
	}
	int oddmax=0,evenmax=0;
	int index=0;
	for (int i=0;i<n;i++) {
		if (smallest.count(a[i])) {
			if (index%2==0) {
				evenmax=max(a[i],evenmax);
			}
			else {
				oddmax=max(a[i],oddmax);
			}
			index++;
		}
	}
	cout<<min(evenmax,oddmax);
}
	