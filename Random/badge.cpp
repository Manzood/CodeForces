#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int loop (vector <int> point, int start) {
	set <int> visited;
	int current=start;
	while (visited.count(current)==0) {
		visited.insert(current);
		current=point[current];
		//debug(current);
	}
	return current;
}

int main() {
	int n;
	cin>>n;
	vector <int> point(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&point[i]);
		point[i]--;
	}
	int ans;
	for (int i=0;i<n;i++) {
		ans=loop(point,i);
		printf("%d ",ans+1);
	}
	printf("\n");
}
