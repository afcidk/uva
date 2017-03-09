#include<stdio.h>

int main() {
	int n, count = 0;
	scanf("%d", &n);
	while(n--){
		double a, b;
		scanf("%lf%lf", &a, &b);
		printf("Case %d: %.2lf\n", ++count, a+5*b/9);
	}
	return 0;
}
