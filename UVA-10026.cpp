#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct S{
	int ind;
	double rate;

	bool operator< (const struct S &t) const{
		return rate>t.rate;
	}
}x[1005];

int main() {
	int c, first=1;
	scanf("%d", &c);

	while(c--){
		int n, a, b;
		int i;
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%d%d", &a, &b);
			x[i].ind=i+1;
			x[i].rate=(double)b/a;
		}
		sort(x, x+n);

		if(!first)	printf("\n");
		first=0;
		printf("%d", x[0].ind);
		for(i=1; i<n; i++)	printf(" %d", x[i].ind);
		printf("\n");
	}
}
