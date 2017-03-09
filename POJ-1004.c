#include<stdio.h>

int main() {
	double ans=0, x, count = 0;
	while(scanf("%lf", &x) == 1){
		ans+=x;
		count++;
	}
	printf("$%.2lf\n", ans/count);
}
