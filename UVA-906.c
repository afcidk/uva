#include<stdio.h>

int main() {
	long long int a, b;
	long double eps;
	while(scanf("%ld%ld%Lf", &a, &b, &eps)==3){
		long double front = (long double)a/b, back=0;
		long long int c=0, d=1;
		while(1){
			if(back-front<=eps+1e-18 && back>front)	{
				printf("%ld %ld\n", c, d);
				break;
			}
			while((long double)c/d > front+eps)	d++;
			while((long double)c/d <= front){
				c++;
			}
			back = (long double)c/d;
		}
	}
	return 0;
}
