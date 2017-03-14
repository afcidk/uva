#include<cstdio>
#include<iostream>
#include<cmath>
#include<unistd.h>
#define MIN_R 1e-6
#define eps 1e-12
#define pi 2.0*acos(0.0)
using namespace std;

int main() {
	int n, first=1;
	scanf("%d", &n);

	while(n--){
		double h, b, r, ans=0;

		scanf("%lf%lf", &b, &h);
		r=b*h/(b+sqrt(b*b+4*h*h));
		ans+=2*r*pi;

		while(true){
			b*=(h-2*r)/h;
			h*=(h-2*r)/h;
			r=b*h/(b+sqrt(b*b+4*h*h));
			if(r<MIN_R)	break;
			ans+=2*r*pi;
		}
		if(!first)	printf("\n");
		first=0;
		printf("%13.6lf\n", ans);
	}
	return 0;
}
