#include<stdio.h>

int main() {
	double a, b;
	while(scanf("%lf:%lf", &a, &b) == 2 && (a||b)){
		double h = a*30;
		double m = b*6;
		h+=m/12;
		h = (h-m)>0?(h-m):(m-h);
		if(h>180)	printf("%.3lf\n", 360-h);
		else printf("%.3lf\n", h);
	}
	return 0;
}
