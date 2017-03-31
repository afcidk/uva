#include<iostream>
#include<cstdio>
#include<cmath>
#include<unistd.h>
#define eps 1e-12
using namespace std;

int main() {
	double p,q,r,s,t,u;
	while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u)==6){

		double down = p*exp(-0)+q*sin(0)+r*cos(0)+s*tan(0)+t*0*0;
		double up = p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t*1*1;
		double left=0, right=1;
		if(-u>down || -u<up)	printf("No solution\n");
		else{
			while(left<right){
				double	mid = (left+right)/2;
				double	now = p*exp(-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid;
				
				if(now+u > eps)	left=mid;
				else if(now+u < -eps)	right=mid;
				else if(now+u < eps){
					printf("%.4lf\n", mid);
					break;
				}
			}
		}
	}
	return 0;
}
