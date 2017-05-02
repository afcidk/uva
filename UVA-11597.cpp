#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	int count=0;
	while(scanf("%d", &n)==1 && n){

		//(n*(n-1)/2)/(n-1) = n/2
		printf("Case %d: %d\n", ++count, n/2);
	}
	return 0;
}
